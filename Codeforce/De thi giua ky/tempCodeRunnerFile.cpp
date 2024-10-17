// Ý tưởng:
// Chia N điểm thành K tập (có ít nhất 1 phần tử), xong mỗi xe sẽ chỉ chạy qua các điểm trong mỗi tập
// Quay lui để tìm ra đường đi ngắn của mỗi xe trong tập điểm của riêng nó (cur_min)
// --> Đối với mỗi cách chia: Đường đi lớn nhất của tất cả K xe là: local_max = max( tất cả các cur_min )
// --> Đáp án của bài toán là: res = min ( local_max của tất cả các cách chia )
#include<bits/stdc++.h>

using namespace std;

int n, k;
int c[1001][1001]; // trọng số các đoạn đường

bool visited[1001]; // kiểm tra các điểm đã thăm

vector<vector<int>> sub(100); // Tập các đỉnh của K tập trong mỗi cách chia

vector<vector<int>> res_route(100); // lưu lộ trình tối ưu của bài toán
vector<vector<int>> local_route(100); // Lộ trình tối ưu trong 1 cách chia 
vector<int> cur_route; // Lộ trình của 1 xe tại thời điểm xét

int res = INT_MAX; // kết quả tối ưu của bài toán
int local_max = 0; // quãng đường dài nhất của K xe trong 1 trường hợp đang xét (mỗi cách chia)
int cur_min = INT_MAX; // quãng đường ngắn nhất của mỗi xe trong lộ trình của riêng nó

int cur = 0; // quãng đường xe id_v đã đi

void input(){
	scanf("%d %d", &n, &k);
	for( int i =0; i<=n; ++i){
		for( int j = 0; j<=n; ++j){
			scanf("%d", &c[i][j]);
		}
	}
}

bool divideIntoSubsets(int num){ // chia N điểm cho K nhóm --- bit mask 
// K nhóm này không cần quan trọng thứ tự và mỗi nhóm có ít nhất 1 phần tử
// --> Để tránh xét bị lặp: Mặc định các phần tử lớn nhất trong K tập phải xếp theo thứ tự (*)

// num là một số hệ K (K = 2 - nhị phân, K = 10 - thập phân, ...) để biểu diễn 1 cách chia

	vector<int> max_sub(k, 0);  // Lưu phần tử lớn nhất trong subset k

	for( int i = n - 1; i>=0; --i){
		int sub_id = num/ (int) pow(k, i);
		sub[sub_id].push_back(i + 1);
		if( max_sub[sub_id] == 0) max_sub[sub_id] = i + 1;
		num %= (int) pow(k, i);
	}
	
	for( int i = 0; i < k - 1 ; ++i){
		if( max_sub[i] < max_sub[i + 1] ) return false; // loại vì sai thứ tự (*)
		if( sub[i].empty()) return false;// loại trường hợp chia ra tập rỗng
	}

	if( sub[k - 1].empty()) return false;
	return true;
}

void Try(int id_v, int u){ // quay lui tìm đường ngắn nhất của xe id_v trong cách chia hiện tại
	for( int i : sub[id_v] ){ // sub[id_v] là những tập đỉnh được chia cho xe id_v
		if( !visited[i] ){
			cur_route.push_back(i);
			visited[i] = true;
			
			cur += c[cur_route[u - 1]][cur_route[u]];
			
			if( u == sub[id_v].size() ) {
				if( cur_min > cur ){ // + c[cur_route[u]][0] nếu điểm cuối lộ trình quay lại về 0
					cur_min =  cur ;//+ c[cur_route[u]][0];
					local_route[id_v] = cur_route; // ghi nhan quang duong
				}
			}
			else Try(id_v, u+1);
			
			cur -= c[cur_route[u - 1]][cur_route[u]];
			visited[i] = false;
			cur_route.pop_back();
		}
	}
}

void init(){ // reset các biến trước khi chia lại
	for( int i = 0; i<k; ++i) {
		sub[i].clear();
		local_route[i].clear();
	}
	memset(visited, 0, sizeof(visited));
	local_max = 0;
}

void print(){ // in ra kết quả của cả bài toán
	cout << k << endl;
	for( int i = 0; i<k ; ++i){
		cout << res_route[i].size() << endl;
		for( auto x : res_route[i]) cout << x << " ";
		cout << endl;
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	//freopen("data.txt", "r", stdin);
	input();
	// int cnt = 0;
	for( int i = 0; i< pow(k, n-1); ++i){ 
		// cout << "---------" << i << "-------------" << endl;
		init();
		if( !divideIntoSubsets(i)) continue; // Chia N ra thành K tập 
		// cnt += 1;
		for( int i = 0; i<k; ++i){ // Quay lui tìm đường đi tối ưu cho k lộ trình
			// cout << "sub " << i << ": ";
			// for( auto _ : sub[i]) cout << _ << " ";
			// cout << endl;
			cur_min = INT_MAX;
			cur_route.clear();
			cur = 0;

			cur_route.push_back(0);
			Try(i, 1);

			// cout << i << " " << cur_min << " -- " ;
			// for( int _ : local_route[i]) cout << _ << " ";
			// cout << endl;
			local_max = max(cur_min, local_max); // Lưu quãng đường dài nhất trong k xe của cách chia này

		}
		
		// cout << cur_max << "--" << endl;
		if( res > local_max){ // Cập nhật đáp án tối ưu
			res_route = local_route;
			res = local_max;
		}
	}
	// cout << "cnt: " << cnt << endl; 
	// cout << res << endl;
	print();
	return 0;
}
