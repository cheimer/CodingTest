/*
/*
 *  Link : https://www.acmicpc.net/problem/5567
 #1#

#include "iostream"
#include "unordered_map"
#include "set"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> listMap;

    for (int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;

        if (listMap.count(a) == 0)
        {
            listMap[a] = vector<int>();
        }
        if (listMap.count(b) == 0)
        {
            listMap[b] = vector<int>();
        }
        listMap[a].push_back(b);
        listMap[b].push_back(a);
    }


    if (listMap.count(1) == 0)
    {
        cout << 0;
    }
    else
    {
        set<int> answers;
        
        answers.insert(listMap[1].begin(), listMap[1].end());
        answers.insert(1);
        
        for (int person : listMap[1])
        {
            answers.insert(listMap[person].begin(), listMap[person].end());
        }

        cout << answers.size() - 1;
        
    }
    
}
*/
