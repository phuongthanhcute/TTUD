from ortools.sat.python import cp_model

def print_result(solver, x, data):
    print('Kết quả bài toán: ', solver.ObjectiveValue())
    for k in range(1, data['K']+1):
        print(f"Thông tin đường đi của bưu tá {k}:")
        str_route = '0 -> '
        route = [0]
        route_distance = 0
        for t in range(1, data['N']+2):
            route.append(solver.Value(x[k,t]))
            route_distance += data['dis_matrix'][route[-1]][route[-2]]
            if route[-1] != 0:
                str_route += f'{route[-1]} -> '
            if route[-1] == 0:
                str_route += '0'
                break

        print('Đường đi:', str_route)
        print('Tổng khoảng cách:', route_distance)

def print_result_openerp(solver, x, data):
    print(data['K'])
    for k in range(1, data['K']+1):
        route = [0]
        for t in range(1, data['N']+2):
            route.append(solver.Value(x[k,t]))
            if route[-1] == 0:
                route = route[:-1]
                break

        print(len(route))
        print(' '.join(str(pos) for pos in route))

def create_data_model():
    """ Stores the data for the problem """
    data = {}
    # Number of dest and postman
    data['N'], data['K'] = tuple(map(int, input().split()))
    # Distance matrix
    data['dis_matrix'] = [list(map(int, input().split())) for i in range(data['N']+1)]

    return data

def setup_model(data, non_cycle_constraint='MTZ'):

    model = cp_model.CpModel()

    # Variables
    x = {}
    for k in range(1, data['K']+1):
        for t in range(0, data['N']+2):
            x[k,t] = model.NewIntVar(0, data['N'], f'x[{k},{t}]')

    # Constraints

    ## Xuất phát từ bưu điện (điểm 0)
    for k in range(1, data['K']+1):
        model.Add(x[k,0] == 0)

    ## Kết thúc hành trình tại 0 và sau đó dừng tại 0
    for k in range(1, data['K']+1):
        for t in range(1, data['N']+1):
            bool_cons = model.NewBoolVar(f'Bưu tá {k} kết thúc hành trình tại bước {t}')
            model.Add(x[k,t] == 0).OnlyEnforceIf(bool_cons)
            model.Add(x[k,t] != 0).OnlyEnforceIf(bool_cons.Not())
            model.Add(x[k,t+1] == 0).OnlyEnforceIf(bool_cons)

    ## Một điểm chỉ được đi qua tối đa một lần
    for k1 in range(1, data['K']+1):
        for k2 in range(1, data['K']+1):
            for t1 in range(0, data['N']+2):
                for t2 in range(0, data['N']+2):
                    if (k1 == k2 and t1 != t2) or k1 != k2:
                        bool_cons = model.NewBoolVar(f'x[{k1},{t1}] == x[{k2},{t2}]')
                        model.Add(x[k1,t1] == x[k2,t2]).OnlyEnforceIf(bool_cons)
                        model.Add(x[k1,t1] != x[k2,t2]).OnlyEnforceIf(bool_cons.Not())
                        model.Add(x[k1,t1] == 0).OnlyEnforceIf(bool_cons)

    ## Tổng vị trí các điểm đi qua bằng tổng vị trí tất cả các điểm
    # Kết hợp với điều kiện trên ta được mỗi điểm phải đi qua đúng một lần
    location_sum = int(data['N']*(data['N']+1)/2)
    model.Add(sum(list(x.values())) == location_sum)

    # Hàm mục tiêu
    max_dis = sum(sum(data['dis_matrix'][i]) for i in range(0, len(data['dis_matrix'])))

    ## Độ dài đường đi mỗi bưu tá
    flatten_dis_matrix = []
    for i in range(0, data['N']+1):
        for j in range(0, data['N']+1):
            flatten_dis_matrix.append(data['dis_matrix'][i][j])
    
    path_lens = []
    for k in range(1, data['K']+1):
        c_k = []
        for i in range(1, data['N']+2):
            # c là độ dài đoạn thứ i, đi từ x[k][i-1] tới x[k][i]
            # c = dis_matrix[ x[k][i-1] ][ x[k][i] ]
            c = model.NewIntVar(0, max_dis, f'Độ dài đoạn thứ {i} trong đường đi của bưu tá {k}')
            # c = dis_matrix[ x[k][i-1] ][ x[k][i] ] == flatten_dis_matrix[ (data['N']+1)*x[k][i-1] + x[k][i] ]
            index = model.NewIntVar(0, int((data['N']+1)**2), f'Index cho đoạn thứ {i} của bưu tá {k}')
            model.Add(index == (data['N']+1)*x[k,i-1] + x[k,i])
            model.AddElement(index, flatten_dis_matrix, c)
            c_k.append(c)
        path_len_k = model.NewIntVar(0, max_dis, f'Độ dài đường đi của bưu tá {k}')
        model.Add(path_len_k == sum(c_k))
        path_lens.append(path_len_k)

    ## Hàm mục tiêu
    obj = model.NewIntVar(0, max_dis, 'obj')
    model.AddMaxEquality(obj, path_lens)
    model.Minimize(obj)

    return model, x

if __name__ == "__main__":

    data = create_data_model()
    model, x = setup_model(data)
    solver = cp_model.CpSolver()

    status = solver.Solve(model)

    if status == cp_model.OPTIMAL:
        print_result_openerp(solver, x, data)