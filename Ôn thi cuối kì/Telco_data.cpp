
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string n1, n2;
    bool checkT = true;
    int h1, m1, s1, h2, m2, s2, total_call = 0;
    cin >> s;
    unordered_map<string, pair<int, int>> m;
    while(s[0] != '#'){
        cin >> n1 >> n2 >> s;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        total_call++;
        int t = (h2 - h1) * 3600 + (m2 - m1) * 60 + s2 - s1;
        if(checkT){
            if(n1.size() != 10 || n1[0] != '0'|| n2.size() != 10 || n2[0] != '0'){
                checkT = false;
            }
        }
        if(m.find(n1) != m.end()){
            m[n1].first++;
            m[n1].second += t;
        }else{
            m[n1] = {1, t};
        }
        cin >> s;
    }
    cin >> s;
    while(s[0] != '#'){
        if(s[1] != 'c'){
            if(s[8] == 'c'){
                cin >> s;
                printf("%d\n", m[s].first);
            }else{
                printf("%d\n", total_call);
            }
        }else{
            if(s[2] == 'o'){
                cin >> s;
                printf("%d\n", m[s].second);
            }else{
                if(checkT) printf("1\n");
                else printf("0\n");
            }
        }
        cin >> s;
    }
}

