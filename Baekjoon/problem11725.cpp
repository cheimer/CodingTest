/*
/*
 *  Link : https://www.acmicpc.net/problem/11725
 #1#

#include "iostream"
#include "vector"

using namespace std;

void SetParent(int currentNum, vector<int>& nodeParent, const vector<vector<int>>& nodeInfos)
{
    for (int nodeNum : nodeInfos[currentNum])
    {
        if (nodeParent[nodeNum] != 0) continue;

        nodeParent[nodeNum] = currentNum;
        SetParent(nodeNum, nodeParent, nodeInfos);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> nodeInfos(N + 1, vector<int>());
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        nodeInfos[a].push_back(b);
        nodeInfos[b].push_back(a);
    }

    vector<int> nodeParent(N + 1, 0);

    SetParent(1, nodeParent, nodeInfos);

    for (int i = 2; i < nodeParent.size(); i++)
    {
        cout << nodeParent[i] << '\n';
    }
    
}
*/
