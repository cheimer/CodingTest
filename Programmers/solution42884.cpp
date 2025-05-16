/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42884
 *
 * Solution : 모든 경로에 최소 하나씩은 포함되게 하는 배열의 최소값
 *
 *  routes : 경로 배열
 *
 *  1 <= routes.Length <= 10000
 *  -30000 <= routes[i][0], routes[i][1] <= 30000
 */

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes)
{
    for (auto& route : routes)
    {
        sort(route.begin(), route.end());
    }

    sort(routes.begin(), routes.end());

    vector<int> CurrentRoute = routes[0];
    int answer = 1;
    
    for (int i = 1; i < routes.size(); i++)
    {
        if (CurrentRoute[1] < routes[i][0])
        {
            answer++;
            CurrentRoute = routes[i];
        }
        else
        {
            if (CurrentRoute[1] < routes[i][1])
            {
                CurrentRoute[0] = routes[i][0];
            }
            else
            {
                CurrentRoute = routes[i];
            }
        }
    }

    
    return answer;
}
