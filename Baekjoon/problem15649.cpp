/*
/*
 *  Link : https://www.acmicpc.net/problem/15649
 #1#

#include <vector>

#include "iostream"

using namespace std;

int maxLen;
int maxNum;

void DFS(int currentLen, vector<int>& listVec, vector<bool>& visited)
{
    if (currentLen == maxLen)
    {
        for (int i = 0; i < maxLen; i++)
        {
            cout << listVec[i] << ' ';
        }
        cout<<'\n';
        return;
    }

    for (int currentNum = 1; currentNum <= maxNum; currentNum++)
    {
        if (!visited[currentNum])
        {
            listVec.push_back(currentNum);
            visited[currentNum] = true;
            
            DFS(currentLen + 1, listVec, visited);

            listVec.pop_back();
            visited[currentNum] = false;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> maxNum >> maxLen;

    vector<int> listVec;
    vector<bool> visited(maxNum + 1, false);
    
    DFS(0, listVec, visited);
    
}
*/
