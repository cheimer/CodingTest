/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42628
 *
 * Solution : 연산에 따라 [최댓값, 최소값] 출력 / 비어있다면 [0, 0] 출력
 * I Num : Input Num / D Num : 최대값삭제 / D -Num : 최소값 삭제
 *
 * 1 <= operations <= 1000000
 * 
 */

#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    deque<int> LesserIntQue;

    for (auto operation : operations)
    {
        bool bIsInput = operation[0] == 'I';
        bool bIsDeleteMax = operation[2] == '1';
        
        if (bIsInput)
        {
            LesserIntQue.push_back(stoi(operation.substr(2)));
            sort(LesserIntQue.begin(), LesserIntQue.end(), greater<int>());
        }
        else
        {
            if (LesserIntQue.empty()) continue;
            
            if (bIsDeleteMax)
            {
                LesserIntQue.pop_front();
            }
            else
            {
                LesserIntQue.pop_back();
            }
        }
    }
    
    vector<int> answer;
    if (LesserIntQue.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (LesserIntQue.size() == 1)
    {
        answer.push_back(LesserIntQue.front());
        answer.push_back(LesserIntQue.front());
    }
    else
    {
        answer.push_back(LesserIntQue.front());
        answer.push_back(LesserIntQue.back());
    }
    
    return answer;
}
