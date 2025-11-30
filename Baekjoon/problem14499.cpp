/*
/*
 *  Link : https://www.acmicpc.net/problem/14499
#1#

#include "iostream"
#include "vector"

using namespace std;

//0 - top, 1 - up, 2 - right, 3 - left, 4 - down, 5 - bottom
void Rolling(vector<int>& dice, const int dir)
{
    int tmp = dice[0];
    switch (dir)
    {
    case 1:
        dice[0] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = tmp;
        break;
    case 2:
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
        break;
    case 3:
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
        break;
    case 4:
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = tmp;
        break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, currentX, currentY, K;
    cin >> N >> M >> currentX >> currentY >> K;

    vector<vector<int>> tile(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tile[i][j];
        }
    }

    const int dx[5] = {0, 0, 0, -1, 1};
    const int dy[5] = {0, 1, -1, 0, 0};

    vector<int> dice(6, 0);

    for (int i = 0; i < K; i++)
    {
        int order;
        cin >> order;

        int nextX = currentX + dx[order];
        int nextY = currentY + dy[order];

        if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;
        Rolling(dice, order);

        cout << dice[0] << '\n';

        if (tile[nextX][nextY] == 0)
        {
            tile[nextX][nextY] = dice[5];
        }
        else
        {
            dice[5] = tile[nextX][nextY];
            tile[nextX][nextY] = 0;
        }

        currentX = nextX;
        currentY = nextY;
        
    }
    
}
*/
