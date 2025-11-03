/*
/*
 *  Link : https://www.acmicpc.net/problem/10026
 #1#

#include "iostream"
#include "vector"
#include "functional"

using namespace std;

void DFS(const int currentX, const int currentY, const char currentVal, const function<bool(char, char)>& compare,
    vector<vector<bool>>& visited, const vector<vector<char>>& tile)
{
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

    visited[currentX][currentY] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextX = currentX + dx[i];
        int nextY = currentY + dy[i];
        
        if (nextX < 0 || nextX >= visited.size() || nextY < 0 || nextY >= visited.size()) continue;
        if (visited[nextX][nextY]) continue;
        
        if (!compare(tile[nextX][nextY], currentVal)) continue;
        
        DFS(nextX, nextY, currentVal, compare, visited, tile);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<char>> tile(N, vector<char>(N, ' '));

    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++)
        {
            tile[i][j] = tmp[j];
        }
    }

    vector<vector<bool>> defaultVisited(N, vector<bool>(N, false));
    vector<vector<bool>> RGVisited(N, vector<bool>(N, false));
    int defaultNum = 0;
    int RGNum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (defaultVisited[i][j] == false)
            {
                defaultNum++;
                DFS(i, j, tile[i][j],
                    [](char A, char B)-> bool
                    {
                        return A == B;
                    },
                defaultVisited, tile);
            }
            
            if (RGVisited[i][j] == false)
            {
                RGNum++;
                DFS(i, j, tile[i][j],
                   [](char A, char B)-> bool
                   {
                        if (A == 'B' && B == 'B') return true;
                        if (A != 'B' && B != 'B') return true;
                        return false;
                   },
               RGVisited, tile);
            }
        }
    }
    
    cout <<defaultNum << ' ' << RGNum;
    
} 
*/
