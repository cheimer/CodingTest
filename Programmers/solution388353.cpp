// Link : https://school.programmers.co.kr/learn/courses/30/lessons/388353

/*
2<= storage.length <= 50
2<= storage[i].length <= 50
storage[i][j] 는 알파벳 대문자

1 <= requests.length <= 100
1 <= requests[i].length <= 2
requests[i] 는 한 종류의 알파벳 대문자

answer = 남은 storage 수
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

static int storageIndex[60][60] = { };

void FoundAll(const int foundNum)
{
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (storageIndex[i][j] == foundNum)
            {
                storageIndex[i][j] = 0;
            }
        }
    }
}

void FoundNearZero(const int foundNum)
{
    vector<pair<int, int>> foundIndexArray;
    
    stack<pair<int, int>> stackArray;
    stackArray.emplace(0, 0);

    int visitedIndex[60][60] = { };
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!stackArray.empty())
    {
        pair<int, int> topIndex = stackArray.top();
        visitedIndex[topIndex.first][topIndex.second] = 1;
        stackArray.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = topIndex.first + dx[i];
            int nextY = topIndex.second + dy[i];

            if (nextX >= 0 && nextX < 60 && nextY >= 0 && nextY < 60)
            {
                if (storageIndex[nextX][nextY] == foundNum)
                {
                    foundIndexArray.emplace_back(nextX, nextY);
                    visitedIndex[nextX][nextY] = 1;
                }
                else if (storageIndex[nextX][nextY] == 0 && visitedIndex[nextX][nextY] == 0)
                {
                    stackArray.emplace(nextX, nextY);
                }
            }
        }
    }
    
    for (auto index : foundIndexArray)
    {
        storageIndex[index.first][index.second] = 0;
    }
}

int solution(vector<string> storage, vector<string> requests)
{
    for (int i = 0; i < storage.size(); i++)
    {
        for (int j = 0; j < storage[i].length(); j++)
        {
            storageIndex[i + 1][j + 1] = static_cast<int>(storage[i][j]);
        }
    }

    for (string request : requests)
    {
        if (request.size() > 1)
        {
            FoundAll(static_cast<int>(request[0]));
        }
        else
        {
            FoundNearZero(static_cast<int>(request[0]));
        }
    }

    
    int answer = 0;
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (storageIndex[i][j] != 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}