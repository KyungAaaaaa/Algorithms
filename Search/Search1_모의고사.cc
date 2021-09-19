/**
 * https://programmers.co.kr/learn/courses/30/lessons/42840
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX     10001

#define NO1_P   5
#define NO2_P   8
#define NO3_P   10
// 1번 수포자 최소 패턴 : 5
// 2번 수포자 최소 패턴 : 8
// 3번 수포자 최소 패턴 : 10

int No_1[] = {1,2,3,4,5};
int No_2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int No_3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int Calc_1(vector<int> answer){
    int ans = 0;
    for(int i = 0; i < answer.size(); i++){
        if(No_1[i % NO1_P] == answer[i]){
            ans++;
        }
    }
    return ans;
}

int Calc_2(vector<int> answer){
    int ans = 0;
    for(int i = 0; i < answer.size(); i++){
        if(No_2[i % NO2_P] == answer[i]){
            ans++;
        }
    }
    return ans;
}

int Calc_3(vector<int> answer){
    int ans = 0;
    for(int i = 0; i < answer.size(); i++){
        if(No_3[i % NO3_P] == answer[i]){
            ans++;
        }
    }
    return ans;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int ans1 = Calc_1(answers);
    int ans2 = Calc_2(answers);
    int ans3 = Calc_3(answers);

    // 가장 높은 점수를 받은 사람이 한명일 경우 한명만 삽입
    // 가장 높은 점수를 받은 사람이 여러명일 경우 오름차순으로 번호를 삽입

    if(ans1 > ans2){
        if(ans1 > ans3){
            // 1만 삽입
            answer.push_back(1);
        }
        else if(ans1 == ans3){
            // 1, 3 삽입
            answer.push_back(1);
            answer.push_back(3);
        }
        else{
            // 3만 삽입
            answer.push_back(3);
        }
    }
    else if(ans1 == ans2){
        if(ans1 > ans3){
            // 1, 2만 삽입
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(ans1 == ans3){
            // 1, 2, 3 삽입
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            // 3만 삽입
            answer.push_back(3);
        }
    }
    else{
        if(ans2 > ans3){
            // 2만 삽입
            answer.push_back(2);
        }
        else if(ans2 == ans3){
            // 2, 3 삽입
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            // 3만 삽입
            answer.push_back(3);
        }
    }
    return answer;
}