/*
/*
 *  Link : https://www.acmicpc.net/problem/1926
 #1#

#include <string>

#include "iostream"
#include "vector"

using namespace std;

void GetMaxSizeTile(int xPos, int yPos, int& currentSize, const vector<vector<int>>& tileVec, vector<vector<bool>>& visitedVec)
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    visitedVec[xPos][yPos] = true;
    currentSize++;
    
    for (int i = 0; i < 4; i++)
    {
        int currentX = xPos + dx[i];
        int currentY = yPos + dy[i];
        if (currentX < 0 || currentX >= tileVec.size() || currentY < 0 || currentY >= tileVec[0].size())
        {
            continue;
        }
        if (visitedVec[currentX][currentY] || tileVec[currentX][currentY] == 0)
        {
            continue;
        }
        
        visitedVec[currentX][currentY] = true;
        GetMaxSizeTile(currentX, currentY, currentSize, tileVec, visitedVec);
        
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int col, row;

    cin >> col >> row;
    vector<vector<int>> tileVec(col, vector<int>(row, 0));
    vector<vector<bool>> visitedVec(col, vector<bool>(row, false));

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            int isValidTile;
            cin >> isValidTile;
            tileVec[i][j] = isValidTile;
        }
    }

    int maxSize = 0;
    int picNum = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (!visitedVec[i][j] && tileVec[i][j] == 1)
            {
                int currentSize = 0;
                GetMaxSizeTile(i, j, currentSize, tileVec, visitedVec);
                picNum++;
                
                maxSize = max(maxSize, currentSize);
            }
        }
    }

    cout<<picNum<<'\n'<<maxSize;
    
}
*/
