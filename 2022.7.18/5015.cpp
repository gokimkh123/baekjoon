// 난이도 : 골드3, 유형 : dp

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<string> vc;

string P,s;
int memo[101][101];
bool match(int P_idx,int s_idx){

    int &ret = memo[P_idx][s_idx];

    if(ret != -1)  // 메모이제이션
        return ret;

    if(P_idx < P.size() && s_idx < s.size() && P[P_idx] == s[s_idx])   // 대응할 수 있을 때까지 재귀를 돌린다.
        return ret = match(P_idx + 1, s_idx + 1);

    if(P_idx == P.size())     // 패턴 끝에 도달해서 끝난 경우 -> 찾고자 하는 문자열도 끝나야 함
        return ret = (s_idx == s.size());

    if(P[P_idx] == '*')     // *만나서 끝난 경우 -> *에 몇 글자를 대응해야 할지 재귀 호출
        return ret = match(P_idx + 1, s_idx) || (match(P_idx, s_idx + 1) && s_idx < s.size());

    return ret = 0;


}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> P;

    int n;
    cin >> n;

    while(n--){
        cin >> s;

        memset(memo,-1,sizeof(memo));

        if(match(0,0))
            cout << s << "\n";

    }
}
