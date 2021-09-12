/**
 * https://www.acmicpc.net/problem/14719
 */

#include <iostream>

using namespace std;

#define MAX 500

int map[MAX + 1];
int ans = 0;
int H, W;

// 다음 두가지 조건이 같이 성립할 경우 가능

// 1. 왼쪽 중에 현재 빗물을 떨어뜨리는 개수보다 크거나 같은 벽이 하나라도 있으면 된다.
// 2. 오른쪽 중에 현재 빗물을 떨어뜨리는 개수보다 크거나 같은 벽이 하나라도 있으면 된다.

int main()
{
    cin >> H >> W;

    for(int i = 0; i < W; i++){
        cin >> map[i];
    }

    for(int i = 1; i < W - 1; i++){
        for(int h = H - map[i]; h > 0; h--){
            bool bleft = false;
            bool bright = false;

            // 왼쪽 검사
            for(int left = 0; left < i; left++){
                if(map[left] >= h + map[i]){
                    bleft = true;
                    break;
                }
            }

            for(int right = i + 1; right < W; right++){
                if(map[right] >= h + map[i]){
                    bright = true;
                    break;
                }   
            }
            if(bleft && bright){
                ans += h;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}