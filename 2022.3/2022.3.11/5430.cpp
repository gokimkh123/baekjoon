//난이도 : 골드5, 유형 : 파싱, deque

#include <bits/stdc++.h>
#define l long long
#define INF 2e9
#define p pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;cin >> t;

    while(t--){
        deque<int> s;
        string P,c;
        int n,temp = 0;

        cin >> P >> n >> c;

        for(auto &i : c){
            if(i == '[' || i == ']') continue;

            if(i == ','){
                s.push_back(temp);
                temp = 0;
                continue;
            }
            int save = i - '0';
            temp *= 10;
            temp += save;
        }

        if(temp != 0) s.push_back(temp);

        bool check = false,left = true;

        for(auto &i : P){
            if(i == 'R') left = !left;
            else if(i == 'D'){
                if(left){
                    if(s.empty()){
                        check = true;
                        break;
                    }
                    s.pop_front();
                }
                else if(!left){
                    if(s.empty()){
                        check = true;
                        break;
                    }
                    s.pop_back();
                }
            }
        }




        if(check) cout << "error\n";
        else{
            cout << '[';

            while(!s.empty()){
                if(left){
                    cout << s.front();
                    s.pop_front();
                    if(!s.empty()) cout << ",";
                }
                else{
                    cout << s.back();
                    s.pop_back();
                    if(!s.empty()) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}


