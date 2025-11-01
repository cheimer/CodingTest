/*
/*
 *  Link : https://www.acmicpc.net/problem/1941
 #1#

#include <queue>

#include "iostream"
#include "vector"

using namespace std;

int answerNum = 0;

bool IsLine(const vector<int>& answerVec)
{
    vector<vector<int>> tile(5, vector<int>(5, -1));
    queue<pair<int, int>> indexQue;
    
    for (int index : answerVec)
    {
        int xPos = index / 5;
        int yPos = index % 5;
        tile[xPos][yPos] = 0;

        if (indexQue.empty())
        {
            indexQue.emplace(xPos, yPos);
            tile[xPos][yPos] = 1;
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int depth = 1;
    
    while (!indexQue.empty())
    {
        int xPos = indexQue.front().first;
        int yPos = indexQue.front().second;
        indexQue.pop();
        
        if (depth == 7)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = xPos + dx[i];
            int nextY = yPos + dy[i];

            if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5)
            {
                continue;
            }
            if (tile[nextX][nextY] != 0)
            {
                continue;
            }

            depth++;
            tile[nextX][nextY] = depth;
            indexQue.emplace(nextX, nextY);
        }
    }

    return false;
}

void DFS(int currentIndex, const vector<bool>& listVec, vector<int>& answerVec)
{
    if (answerVec.size() == 7)
    {
        int somNum = 0;
        for (int index : answerVec)
        {
            if (listVec[index] == true)
            {
                somNum++;
            }
        }
        if (somNum >= 4 && IsLine(answerVec))
        {
            answerNum++;
        }
        
        return;
    }

    for (int i = currentIndex; i < listVec.size(); i++)
    {
        answerVec.push_back(i);
        DFS(i + 1, listVec, answerVec);
        answerVec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> listVec(25, false);
    for (int i = 0; i < 25; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'S')
        {
            listVec[i] = true;
        }
    }

    vector<int> answerVec;
    DFS(0, listVec, answerVec);

    cout<<answerNum;
}
*/
