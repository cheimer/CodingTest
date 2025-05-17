/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/43105
 *
 * Solution : 배열 중 하나를 선택한 후 다음 배열의 인접한 값을 더할 때 최대값을 찾음
 *
 *  triangle : 배열
 *
 *  1 <= triangle.size <= 500
 *  1 <= triangle[i][j] <= 9999
 *
 */

#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }

    int answer = -1;
    for (auto row : triangle[triangle.size() - 1])
    {
        answer = max(answer, row);
    }
    
    return answer;
}
