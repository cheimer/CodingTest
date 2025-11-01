/*
/*
 *  Link : https://www.acmicpc.net/problem/11003
 #1#

#include "iostream"
#include "queue"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<int> vec;
    priority_queue<int, vector<int>, greater<int>> removedPQ;
    priority_queue<int, vector<int>, greater<int>> storedPQ;

    for (int i = 0; i < N; i++)
    {
        int currentNum;
        cin >> currentNum;
        vec.push_back(currentNum);

        if (storedPQ.size() >= L)
        {
            removedPQ.push(vec[i - L]);
            while (!removedPQ.empty())
            {
                if (removedPQ.top() == storedPQ.top())
                {
                    removedPQ.pop();
                    storedPQ.pop();
                }
                else
                {
                    break;
                }
            }
        }
        storedPQ.push(currentNum);
        cout<<storedPQ.top() << ' ';
        
    }
    
}
*/
