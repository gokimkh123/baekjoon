// 난이도 : 브론즈 5, 유형 : 구현

#include <iostream>
using namespace std;

int main(){
    int l,p,sum ;
    
    cin >> l >> p;
    
    sum = l * p;
    
    for(int i=0;i<5;i++){
        int a;cin >> a;
        cout << a-sum << " "; 
    }
}
