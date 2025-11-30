/*
/*
 *  Link : https://www.acmicpc.net/problem/14503
 #1#

#include "iostream"
#include "vector"

using namespace std;

const int CleanTile = 999;

void CleanUp(vector<vector<int>>& tile, const int currentX, const int currentY, const int dir)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    if (tile[currentX][currentY] == 0)
    {
        tile[currentX][currentY] = CleanTile;
    }

    for (int i = 1; i <= 4; i++)
    {
        int nextI = (dir - i) % 4;
        nextI = nextI < 0 ? nextI + 4 : nextI;

        int nextX = currentX + dx[nextI];
        int nextY = currentY + dy[nextI];

        if (tile[nextX][nextY] == 0)
        {
            CleanUp(tile, nextX, nextY, nextI);
            return;
        }
    }

    if (tile[currentX - dx[dir]][currentY - dy[dir]] != 1)
    {
        CleanUp(tile, currentX - dx[dir], currentY - dy[dir], dir);
        return;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int startX, startY, dir;
    cin >> startX >> startY >> dir;

    vector<vector<int>> tile(N, vector<int>(M, 0));

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            cin >> tile[row][col];
        }
    }

    CleanUp(tile, startX, startY, dir);

    int answer = 0;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            if (tile[row][col] == CleanTile)
            {
                answer++;
            }
        }
    }

    cout << answer;
}
*/
