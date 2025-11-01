/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include <vector>

#include "iostream"
#include "string"
#include "queue"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int col, row;
    cin >> col >> row;

    vector<vector<int>> tiles(col, vector<int>(row, 0));
    vector<vector<int>> visited(col, vector<int>(row, 0));

    for (int i = 0; i < col; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < row; j++)
        {
            int currentNum = stoi(str.substr(j, 1));
            tiles[i][j] = currentNum;
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    queue<pair<int, int>> que;

    que.emplace(0, 0);
    visited[0][0] = 1;

    while (!que.empty())
    {
        int xPos = que.front().first;
        int yPos = que.front().second;
        que.pop();

        if (xPos == col - 1 && yPos == row - 1)
        {
            cout<<visited[xPos][yPos];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = xPos + dx[i];
            int nextY = yPos + dy[i];

            bool bCanTravel =
                nextX >= 0 && nextX < col &&
                nextY >= 0 && nextY < row &&
                tiles[nextX][nextY] == 1 &&
                visited[nextX][nextY] == 0;

            if (bCanTravel)
            {
                visited[nextX][nextY] = visited[xPos][yPos] + 1;
                que.emplace(nextX, nextY);
            }
        }
    }
    
}
*/
