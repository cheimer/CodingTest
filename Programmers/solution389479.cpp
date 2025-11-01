// Link : https://school.programmers.co.kr/learn/courses/30/lessons/389479

/*
 * players : 시간대별 이용자 수
 * m : 서버 한대 이용자 수
 * k : 대여 시간
*/

#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    
    int currentServerNum = 0;
    int serverReturnTime[50] = {};
    int answer = 0;

    for (int i = 0; i < players.size(); i++)
    {
        currentServerNum -= serverReturnTime[i];
        if (players[i] >= m * (currentServerNum + 1))
        {
            int requireServerNum = (players[i] - m * currentServerNum) / m;

            currentServerNum += requireServerNum;
            answer += requireServerNum;
            serverReturnTime[i + k] = requireServerNum;
        }
    }
    
    return answer;
}
