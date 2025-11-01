/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include "iostream"
#include "queue"
#include "set"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N == 1)
    {
        cout<<'0';
        return 0;
    }

    queue<pair<int, int>> que;
    set<int> storedSet;

    if (N % 3 == 0)
    {
        que.emplace(N / 3, 1);
        storedSet.emplace(N / 3);
    }
    if (N % 2 == 0)
    {
        que.emplace(N / 2, 1);
        storedSet.emplace(N / 2);
    }
    que.emplace(N - 1, 1);
    storedSet.emplace(N - 1);

    while (!que.empty())
    {
        int currentN = que.front().first;
        int currentDepth = que.front().second;
        que.pop();
        
        if (currentN == 1)
        {
            cout<<currentDepth << '\n';
            break;
        }
        else
        {
            if (currentN % 3 == 0 && storedSet.count(currentN / 3) == 0)
            {
                que.emplace(currentN / 3, currentDepth + 1);
                storedSet.emplace(currentN / 3);
            }
            if (currentN % 2 == 0 && storedSet.count(currentN / 2) == 0)
            {
                que.emplace(currentN / 2, currentDepth + 1);
                storedSet.emplace(currentN / 2);
            }
            if (storedSet.count(currentN - 1) == 0)
            {
                que.emplace(currentN - 1, currentDepth + 1);
                storedSet.emplace(currentN - 1);
            }
        }
    }
    
}
*/
