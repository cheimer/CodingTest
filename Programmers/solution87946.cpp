/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/87946
 *
 * Solution : 돌 수 있는 던전의 수를 구함
 *
 * k : 현재 피로도
 * vector<vector<int>> dungeons : [최소 필요 피로도, 소모 피로도] * 던전 수
 * 피로도는 같을 수 있음
 *
 * 1 <= k <= 5000
 * 1 <= dungeons[i][0] <= dungeons[i][1] <= 1000
 * 1 <= dungeons.length <= 8
 */

#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    vector<int> PermutationIndex;

    PermutationIndex.reserve(dungeons.size());
    for (int i = 0; i < dungeons.size(); i++)
    {
        PermutationIndex.push_back(i);
    }
    
    int answer = -1;

    do
    {
        int CurrentK = k;
        int CurrentDGNum = 0;
        
        for (int i = 0; i < PermutationIndex.size(); i++)
        {
            if (CurrentK >= dungeons[PermutationIndex[i]][0])
            {
                CurrentK -= dungeons[PermutationIndex[i]][1];
                CurrentDGNum++;
            }
        }

        answer = max(CurrentDGNum, answer);
    }
    while (next_permutation(PermutationIndex.begin(), PermutationIndex.end()));

    
    return answer;
}
