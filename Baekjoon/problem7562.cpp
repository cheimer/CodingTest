/*
/*
 *  Link : https://www.acmicpc.net/problem/7562
 #1#

#include "iostream"
#include "queue"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caseNum;
    cin >> caseNum;

    for (int i = 0; i < caseNum; i++)
    {
        int len;
        cin >> len;
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;

        vector<vector<bool>> visited(len, vector<bool>(len, false));
        queue<pair<int, int>> indexQue;
        indexQue.emplace(startX, startY);

        int answer = -1;

        while (!indexQue.empty())
        {
            size_t queNum = indexQue.size();
            answer++;

            int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
            int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

            bool bIsEnd = false;
            for (; queNum > 0; queNum--)
            {
                int currentX = indexQue.front().first;
                int currentY = indexQue.front().second;
                
                if (currentX == endX && currentY == endY)
                {
                    bIsEnd = true;
                    break;
                }
            
                indexQue.pop();

                for (int i = 0; i < 8; i++)
                {
                    int nextX = currentX + dx[i];
                    int nextY = currentY + dy[i];

                    if (nextX < 0 || nextX >= len || nextY < 0 || nextY >= len) continue;
                    if (visited[nextX][nextY]) continue;

                    visited[nextX][nextY] = true;
                    indexQue.emplace(nextX, nextY);
                    
                }
            }

            if (bIsEnd)
            {
                cout<<answer<<"\n";
                break;
            }
        }
    }
    
}
*/
