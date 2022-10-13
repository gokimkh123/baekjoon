//난이도 : 골드5, 유형 : 재귀, 이진트리, 구조체

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define INF 2e9
#define F first
#define S second
using namespace std;

typedef long long l;
typedef pair<int,int> p;
typedef tuple<int,int,int> tu;
typedef vector<int> vc;

struct Node{
    int value;
    struct Node *Llink;
    struct Node *Rlink;
};

void Insert(struct Node *head,int value){
    struct Node *Newnode = (struct Node *) malloc(sizeof(Node));
    Newnode -> Llink = nullptr, Newnode -> Rlink = nullptr;
    Newnode -> value = value;

    if(head -> Llink == nullptr && head -> Rlink == nullptr){
        head -> Llink = Newnode, head -> Rlink = Newnode;
        return;
    }
    else{
        head = head -> Llink;

        while(1){
            if(head -> value < Newnode -> value){
                if(head -> Rlink == nullptr){
                    head -> Rlink = Newnode;
                    return;
                }
                else head = head -> Rlink;
            }
            else{
                if(head -> Llink == nullptr){
                    head -> Llink = Newnode;
                    return;
                }
                else head = head -> Llink;
            }
        }
    }
}
void Postorder(struct Node *head){
    if(head != nullptr){
        Postorder(head -> Llink);
        Postorder(head -> Rlink);
        cout << head -> value << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    struct Node *head = (struct Node *) malloc(sizeof(Node));

    head -> Llink = nullptr, head -> Rlink = nullptr;

    int n;


    while(cin >> n){
        Insert(head,n);
    }

    Postorder(head -> Llink);

}

