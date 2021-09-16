/**
 * https://www.acmicpc.net/problem/14503
 */

#include <iostream>

using namespace std;

#define MAX_LEN 50
#define WALL    1
#define SPACE   0

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3
// 청소년 문화의집
int N, M;                           // 세로 크기 : N, 가로 크기 : M
int x, y;                           // 로봇 청소기가 있는 칸의 좌표 
int d;                              // 바로브는 방향
            // 북 동 남 서
int xdir[] = {-1, 0, 1, 0};
int ydir[] = {0, 1, 0, -1};

bool check[MAX_LEN][MAX_LEN]; // 청소 체크 여부
int map[MAX_LEN][MAX_LEN];  // 맵

void Input(){
    cin >> N >> M;
    cin >> x >> y >> d;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
}

bool CheckOut(int px, int py){
    if(px < 0 || px >= N || py < 0 || py >= M){
        return true;
    }
    return false;
}
/**
 * @brief 
 * 
 * @param nx    다음 x칸
 * @param ny    다음 y칸
 * @param nd    다음 방향 (북 동 남 서)
 * @param cnt   턴 횟수
 */
void DFS(int cx, int cy, int cd, int result){
    for(int i = 0; i < 4; i++){
        // 현재 방향에서 왼쪽을 확인
        int nd = (cd + 3 - i) % 4;
        int nx = cx + xdir[nd];
        int ny = cy + ydir[nd];

        // 밖이거나 벽일경우
        if(CheckOut(nx, ny) || map[nx][ny] == WALL){
            continue;
        }

        // 밖이나 벽이 아닌경우, 청소해야하는 공간인 경우
        if(check[nx][ny] == false){
            // 현재 위치 청소
            check[nx][ny] = true;
            DFS(nx, ny, nd, result + 1);
        }
    }

    // 왼쪽 방향으로 돌았을 때 청소할 곳이 없으면 뒤로 가기
    do{
        int nd = cd + 2 < 4 ? cd + 2 : cd - 2;
        int nx = cx + xdir[nd];
        int ny = cy + ydir[nd];
        // 밖이 아닐 경우
        if(!CheckOut(nx, ny)){
            // 후진할 수 있는 공간일 때
            if(map[nx][ny] == SPACE){
                DFS(nx, ny, cd, result);
            } else{
                cout << result << endl;
                exit(0);
            }
        }
    } while(0);
}


int main(){
    Input();
    // 현재 자리 청소
    check[x][y] = true;
    DFS(x, y, d, 1);
}

/**

#include <iostream>

using namespace std;

#define MAX_LEN 50
#define WALL    1
#define SPACE   0

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3

int N, M;                           // 세로 크기 : N, 가로 크기 : M
int x, y;                           // 로봇 청소기가 있는 칸의 좌표 
int d;                              // 바로브는 방향
            // 북 동 남 서
int xdir[] = {-1, 0, 1, 0};
int ydir[] = {0, 1, 0, -1};

bool check[MAX_LEN + 1][MAX_LEN + 1]; // 청소 체크 여부
int map[MAX_LEN + 1][MAX_LEN + 1];  // 맵

int turnleft(int _d){
    if(_d == NORTH) return WEST;
    return _d - 1;
}

int turn(int _d){
    if(_d == NORTH) return SOUTH;
    if(_d == EAST) return WEST;
    return _d - 2;
}

void Input(){
    cin >> N >> M;
    cin >> x >> y >> d;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
}

void Solve(){
    // 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색
    memset(check, false, sizeof(check));
    int turncnt;
    int result = 0;
    
    // 시작 위치 청소하고 시작
    check[x][y] = true;
    result++;
    
    while(1){
        turncnt = 0;
        // 1. 왼쪽 방향에 청소하지 않은 공간이 존재한다면 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행
        int nx, ny, nd;

        nd = turnleft(d);
        nx = x + xdir[nd];
        ny = y + ydir[nd];

        turncnt++;

        // 청소하지 않은 공간이고 벽이 아닌 경우
        if(check[nx][ny] == false && map[nx][ny] != WALL){
            // 청소
            check[nx][ny] = true;
            result++;
            // 다음 한 칸 전진
            x = nx;
            y = ny;
            d = nd; 
        } else{
        // 2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
            if(turncnt == 4){
                // 3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                nd = turn(nd);
                nx = x + xdir[nd];
                ny = y + ydir[nd];
                
                // 4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                if(map[nx][ny] == WALL){
                    cout << result << endl;
                    return;
                } else{
                    d = nd;
                    continue;
                }
            }
        }        
    }    
}

int main()
{
    Input();    
    Solve();

    return 0;
}
 * 
 */
