// 난이도 : 실버1, 유형 : queue, 완전탐색

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <stack>
#define l long long
#define INF 2e9
using namespace std;

vector<int> v;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int ans = 0,sum = 0;
    int n,w,L;cin >> n >> w >> L;

    for(int i=0;i<n;i++){
        int a;cin >> a;v.push_back(a);
    }

    for(int i=0;i<n;i++){
        while(1){
            if(q.size() == w){
                sum -= q.front();
                q.pop();
            }

            if(sum + v[i] <= L) break;

            q.push(0);ans++;

        }
        q.push(v[i]);ans++;sum += v[i];
    }
    cout << ans + w;

}
/*
   이해 : w에는 w개의 트럭들만 올라갈 수 있다. L보다 낮은 무게로 지나가야한다 이때 최단시간은?

    1. 현재 다리에 있는 차의 무게의 합 : sum
       현재 다리에 있는 차의 무게 : q
    2. 현재 다리에 있는 차들을 q에 넣기
    3. 만약 sum과 다음 차의 합이 L보다 작고 다리 길이 보다 작으면 q에 넣고 sum값 누적
    4. sum값과 다음차의 무게가 L보다 커지면 차를 진행시키며 size늘리기
    5. 만약 size가 w가 됐다면 차가 다리위에서 빠지므로 sum값을 빼고 q를 빼기
    6. 마지막은 예외처리

 */
