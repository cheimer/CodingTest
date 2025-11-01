// Link : https://school.programmers.co.kr/learn/courses/30/lessons/388352

/*
 *  10 <= n <= 30
 *  1 <= q.length <= 10
 *  q[i].length = 5
 *  1 <= q[i][j] <= n
 *  0 <= ans[i] <= 5
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    vector<int> comb(n, 0);

    for (int i = 0; i < 5; i++)
    {
        comb[n - 1 - i] = 1;
    }

    int answer = 0;
    do
    {
        bool isAnswer = true;
        for (int i = 0; i < q.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < q[i].size(); j++)
            {
                if (comb[q[i][j] - 1] == 1)
                {
                    sum++;
                }
            }

            if (sum != ans[i])
            {
                isAnswer = false;
                break;
            }
        }
        answer = isAnswer ? answer + 1 : answer;
    }
    while (next_permutation(comb.begin(), comb.end()));

    return answer;
}