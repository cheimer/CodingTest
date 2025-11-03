/*
/*
 *  Link : https://www.acmicpc.net/problem/7569
 #1#

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;

    cin >> M >> N >> H;

    vector<vector<vector<int>>> tile(H, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<vector<int>> indexQue;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int tmp;
                cin >> tmp;
                tile[i][j][k] = tmp;

                if (tmp == 1)
                {
                    indexQue.push({i, j, k});
                }
            }
        }
    }

    int answer = -1;
    while (!indexQue.empty())
    {
        answer++;
        size_t queSize = indexQue.size();

        int dx[6] = {0, 0, 0, 0, -1, 1};
        int dy[6] = {0, 0, -1, 1, 0, 0};
        int dz[6] = {-1, 1, 0, 0, 0, 0};

        for (; queSize > 0; queSize--)
        {
            int currentZ = indexQue.front()[0];
            int currentX = indexQue.front()[1];
            int currentY = indexQue.front()[2];
            indexQue.pop();
            
            for (int i = 0; i < 6; i++)
            {
                int nextZ = currentZ + dz[i];
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];

                if (nextZ < 0 || nextZ >= tile.size() ||
                    nextX < 0 || nextX >= tile[0].size() ||
                    nextY < 0 || nextY >= tile[0][0].size()) continue;

                if (tile[nextZ][nextX][nextY] == 1 || tile[nextZ][nextX][nextY] == -1) continue;

                tile[nextZ][nextX][nextY] = 1;
                indexQue.push({nextZ, nextX, nextY});
            }
        }
    }

    for (auto tileH : tile)
    {
        for (auto tileX : tileH)
        {
            for (auto tileY : tileX)
            {
                if (tileY == 0)
                {
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }

    cout<<answer;
}
*/
