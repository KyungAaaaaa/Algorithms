/**
 * https://www.acmicpc.net/problem/5052
 * 
 * 참고 : https://yabmoons.tistory.com/397
 */ 

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * 전화 번호 목록이 일관성이 있는지 없는지 구함
 * 
 * 일관성의 기준
 * 
 * 예시)
 * 1: 911
 * 2: 97 625 999
 * 3: 91 12 54 26
 * 
 * 3번의 경우 91 1까지 입력 시 긴급전화로 전화가 가게 된다.
 * 그러므로 3번에게 전화를 걸 수 있는 방법이 없다
 * 
 * 조건)
 * 1. 1개의 최대 전화 번호 길이는 10
 * 2. 목록에 있던 같은 전화번호는 입력되지 않는다.
 */

#define LEN_MAX 11
#define N_MAX 10001
#define NODE_MAX N_MAX * LEN_MAX

int t, n, N_Idx;
char Phone[N_MAX][LEN_MAX];
string answer;

struct TRIE{
    bool bfinish;
    TRIE *Node[LEN_MAX];

    void Insert(char* cstr);
    bool Call(char *cstr);
};

TRIE *Root, Nodepool[NODE_MAX];

TRIE *Nodeset()
{
    TRIE *NewNode = &Nodepool[N_Idx++];
    NewNode->bfinish = false;
    for (int i = 0; i < LEN_MAX; i++) NewNode->Node[i] = NULL;
    
    return NewNode;
}

void TRIE::Insert(char* cstr){
    if(*cstr == NULL){
        bfinish = true;
        return;
    }
    
    int cur = *cstr - '0';
//    printf("cur : %d, cstr : %c\n", cur, *cstr);
    if(Node[cur] == NULL) Node[cur] = Nodeset();
    Node[cur]->Insert(cstr + 1);
}

bool TRIE::Call(char *cstr)
{
    if(*cstr == NULL) return true;
    if (bfinish == true) return false;

    int cur = *cstr - '0';
    return Node[cur]->Call(cstr + 1);
}

void Initialize(){
    N_Idx = 0;
    Root = Nodeset();
}


void Fail(){
    cout << "NO" << endl;
}

void Success(){
    cout << "YES" << endl;
}

void Start(){
    Initialize();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> Phone[i]; 
    }

    for(int i = 0; i < n; i++) Root->Insert(Phone[i]);
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(flag) flag = Root->Call(Phone[i]);
        else break;
    }

    if(flag) Success();
    else Fail();
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; i++){
        Start();
    }
    return 0;
}