/*
 *  Link : https://www.acmicpc.net/problem/4179
 */

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int WALL = -9999;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> tile(R, vector<int>(C, 0));
    queue<pair<int, int>> moveQue;
    queue<pair<int, int>> fireQue;
    
    for (int i = 0; i < R; i ++)
    {
        for (int j = 0 ; j < C; j++)
        {
            char tmp;
            cin >> tmp;

            switch (tmp)
            {
            case '#':
                tile[i][j] = WALL;
                break;
            case '.':
                tile[i][j] = 0;
                break;
            case 'J':
                tile[i][j] = 0;
                moveQue.emplace(i, j);
                break;
            case 'F':
                tile[i][j] = WALL;
                fireQue.emplace(i, j);
                break;
            default:
                return -1;
            }
        }
    }

    if (moveQue.front().first == 0 || moveQue.front().first == R - 1 || moveQue.front().second == 0 || moveQue.front().second == C - 1)
    {
        cout << '1';
        return 0;
    }

    int time = 0;

    while (!moveQue.empty())
    {
        time++;
        
        while (!fireQue.empty())
        {
            int fireX = fireQue.front().first;
            int fireY = fireQue.front().second;
            
            if (tile[fireX][fireY] == -time) break;
            
            fireQue.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextFireX = fireX + dx[i];
                int nextFireY = fireY + dy[i];

                if (nextFireX < 0 || nextFireX >= R || nextFireY < 0 || nextFireY >= C) continue;
                if (tile[nextFireX][nextFireY] < 0) continue;

                tile[nextFireX][nextFireY] = -time;
                fireQue.emplace(nextFireX, nextFireY);
            }
        }

        while (!moveQue.empty())
        {
            int currentX = moveQue.front().first;
            int currentY = moveQue.front().second;

            if (tile[currentX][currentY] == time) break;
            
            if (currentX == 0 || currentX == R -1 || currentY == 0 || currentY == C - 1)
            {
                cout<< time;
                return 0;
            }

            moveQue.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextMoveX = currentX + dx[i];
                int nextMoveY = currentY + dy[i];

                if (tile[nextMoveX][nextMoveY] != 0) continue;

                tile[nextMoveX][nextMoveY] = time;
                moveQue.emplace(nextMoveX, nextMoveY);
            }
        }

    }

    cout<<"IMPOSSIBLE";

    return 0;
    
}
