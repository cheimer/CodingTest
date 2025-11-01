/*
/*
 *  Link : https://www.acmicpc.net/problem/12852
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
        cout<<'0' << '\n' << '1';
        return 0;
    }

    queue<pair<int, vector<int>>> que;
    set<int> storedSet;

    if (N % 3 == 0)
    {
        vector<int> firstList(1, N / 3);
                
        que.emplace(N / 3, firstList);
        storedSet.emplace(N / 3);
    }
    if (N % 2 == 0)
    {
        vector<int> firstList(1, N / 2);
        
        que.emplace(N / 2, firstList);
        storedSet.emplace(N / 2);
    }

    vector<int> firstList(1, N - 1);
    
    que.emplace(N - 1, firstList);
    storedSet.emplace(N - 1);

    while (!que.empty())
    {
        int currentN = que.front().first;
        vector<int> currentList = que.front().second;
        que.pop();
        
        if (currentN == 1)
        {
            cout << currentList.size() << '\n' << N << ' ';
            for (int k : currentList)
            {
                cout<< k << ' ';
            }
            break;
        }
        else
        {
            if (currentN % 3 == 0 && storedSet.count(currentN / 3) == 0)
            {
                vector<int> tempList = currentList;
                tempList.push_back(currentN / 3);
                
                que.emplace(currentN / 3, tempList);
                storedSet.emplace(currentN / 3);
            }
            if (currentN % 2 == 0 && storedSet.count(currentN / 2) == 0)
            {
                vector<int> tempList = currentList;
                tempList.push_back(currentN / 2);
                
                que.emplace(currentN / 2, tempList);
                storedSet.emplace(currentN / 2);
            }
            if (storedSet.count(currentN - 1) == 0)
            {
                vector<int> tempList = currentList;
                tempList.push_back(currentN - 1);
                
                que.emplace(currentN - 1, tempList);
                storedSet.emplace(currentN - 1);
            }
        }
    }
    
}
*/
