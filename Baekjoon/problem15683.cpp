/*
/*
 *  Link : https://www.acmicpc.net/problem/15683
 #1#

#include "iostream"
#include "vector"

using namespace std;

/*
 *  1 : >, 2 : <>, 3 : ^>, 4 : <^>, 5 : <^v>, 6 : wall, 0 : empty
 #1#

int minEmptyNum = 100;

void ChangePoint(const int currentX, const int currentY, const vector<vector<int>>& tile, vector<vector<int>>& viewPoint, vector<pair<int, int>>& changedPoint)
{
    for (int xPos = 0; xPos < viewPoint.size(); xPos++)
    {
        if (xPos == currentX) continue;

        if (viewPoint[xPos][currentY] == 0 && tile[xPos][currentY] == 0)
        {
            viewPoint[xPos][currentY] = 1;
            changedPoint.emplace_back(xPos, currentY);
        }
    }
    for (int yPos = 0; yPos < viewPoint[0].size(); yPos++)
    {
        if (yPos == currentY) continue;

        if (viewPoint[currentX][yPos] == 0 && tile[currentX][yPos] == 0)
        {
            viewPoint[currentX][yPos] = 1;
            changedPoint.emplace_back(currentX, yPos);
        }
    }

}

void BT(const int currentIndex, const vector<vector<int>>& tile, const vector<pair<int, int>>& ccPoint, vector<vector<int>>& viewPoint)
{
    if (currentIndex >= ccPoint.size())
    {
        int currentNum = 0;
        for (size_t i = 0; i < viewPoint.size(); i++)
        {
            for (size_t j = 0; j < viewPoint[0].size(); j++)
            {
                if (viewPoint[i][j] == 0)
                {
                    currentNum++;
                }
            }
        }

        minEmptyNum = min(minEmptyNum, currentNum);
        return;
    }

    for (int i = currentIndex; i < ccPoint.size(); i++)
    {
        int currentX = ccPoint[i].first;
        int currentY = ccPoint[i].second;

        vector<pair<int, int>> changedPoint;
        ChangePoint(currentX, currentY, tile, viewPoint, changedPoint);
        BT(i + 1, tile, ccPoint, viewPoint);
        
        for (pair<int, int> changed : changedPoint)
        {
            viewPoint[changed.first][changed.second] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> tile(N, vector<int>(M, 0));
    vector<pair<int, int>> ccPoint;
    vector<vector<int>> viewPoint(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int tmp;
            cin >> tmp;
            tmp == 6 ? tile[i][j] = -1 : tile[i][j] = tmp;
            tmp == 0 ? viewPoint[i][j] = 0 : viewPoint[i][j] = 1;

            if (tmp > 0 && tmp <= 5)
            {
                ccPoint.emplace_back(i, j);
            }
        }
    }


    BT(0, tile, ccPoint, viewPoint);


    cout << minEmptyNum;
}
*/
