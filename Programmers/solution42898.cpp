/*
/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42898
 *
 * Solution : 시작점에서 우측, 하단으로만 움직여서 해당 좌표로 갈수 있는 경로의 갯수 % 1000000007
 *
 *  m, n : 배열 크기 및 좌표
 *  puddles : 막힌 지역
 *
 *  1 <= m, n <= 100
 *  0 <= puddles.size <= 10
 *
 #1#

#include <queue>
#include <vector>
#include <string.h>

constexpr long long VISIT_MAX = 1000000007;

using namespace std;

long long tiles[101][101];

int solution(int m, int n, vector<vector<int>> puddles)
{
    memset(tiles, 0, sizeof(tiles));
    
    for (auto puddle : puddles)
    {
        tiles[puddle[0]][puddle[1]] = -1;
    }

    queue<vector<int>> indexQue;
    tiles[1][1] = 1;
    indexQue.push(vector<int>{1, 1});
    
    while (!indexQue.empty())
    {
        vector<int> currentIndex = indexQue.front();
        indexQue.pop();

        if (currentIndex[0] + 1 <= m && tiles[currentIndex[0] + 1][currentIndex[1]] != -1)
        {
            if (tiles[currentIndex[0] + 1][currentIndex[1]] == 0)
            {
                indexQue.push(vector<int>{currentIndex[0] + 1, currentIndex[1]});
            }
            tiles[currentIndex[0] + 1][currentIndex[1]] += tiles[currentIndex[0]][currentIndex[1]];
            if (tiles[currentIndex[0] + 1][currentIndex[1]] >= VISIT_MAX)
            {
                tiles[currentIndex[0] + 1][currentIndex[1]] %= VISIT_MAX;
            }
        }
        if (currentIndex[1] + 1 <= n && tiles[currentIndex[0]][currentIndex[1] + 1] != -1)
        {
            if (tiles[currentIndex[0]][currentIndex[1] + 1] == 0)
            {
                indexQue.push(vector<int>{currentIndex[0], currentIndex[1] + 1});
            }
            tiles[currentIndex[0]][currentIndex[1] + 1] += tiles[currentIndex[0]][currentIndex[1]];
            if (tiles[currentIndex[0]][currentIndex[1] + 1] >= VISIT_MAX)
            {
                tiles[currentIndex[0]][currentIndex[1] + 1] %= VISIT_MAX;
            }
        }
    }
    
    return static_cast<int>(tiles[m][n]);
}
*/
