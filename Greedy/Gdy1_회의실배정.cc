/**
 * https://www.acmicpc.net/problem/1931
 */

// 설명

/**
 * 1개의 회의실
 * 
 * 이를 사용하고자하는 N개의 회의실
 * 
 * 각 회의에 대해 시작시간과 끝나는 시간이 주어짐
 * 
 * 목표 : 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수
 * 
 * 제한 : 회의는 중단 불가, 끝남과 동시에 다른 회의 시작 가능 (즉, 끝나는 시간 = 시작하는 시간 가능 )
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<pair<int,int> > meeting;

int main()
{
    int start, end;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> start >> end;
        meeting.push_back(make_pair(end, start));
    }
    // 종료 시간이 가장 빠른 회의를 벡터 앞에 둔다 
    sort(meeting.begin(), meeting.end());

    int cnt = 1;
    int last = meeting[0].first;

    for(int i = 1; i < n; i++){
        // 첫번째 스케줄 종료 시점이 두번째 스케줄의 시작 시점보다 작거나 같은 경우 
        if(last <= meeting[i].second){
            cnt++;
            last = meeting[i].first;
        }       
    }

    cout << cnt << endl;
    return 0;
}