/*
/*
 *  Link : https://www.acmicpc.net/problem/2910
 #1#

#include "iostream"
#include "map"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;

    map<int, pair<int, int>> numMap;
    
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        if (numMap.count(tmp) == 0)
        {
            numMap[tmp] = {1, i};
        }
        else
        {
            numMap[tmp].first++;
        }
    }

    vector<pair<int, pair<int, int>>> numVec(numMap.begin(), numMap.end());

    sort(numVec.begin(), numVec.end(),
        [](pair<int, pair<int, int>> A, pair<int, pair<int, int>> B) -> bool
        {
            if (A.second.first != B.second.first)
            {
                return A.second.first > B.second.first;
            }
            else
            {
                return A.second.second < B.second.second;
            }
        }
    );

    for (int i = 0; i < numVec.size(); i++)
    {
        for (int j = 0; j < numVec[i].second.first; j++)
        {
            cout << numVec[i].first << ' ';
        }
    }
    
}
*/
