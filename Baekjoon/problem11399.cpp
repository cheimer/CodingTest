/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include "iostream"
#include "queue"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int timeVal;
        cin >> timeVal;
        pq.push(timeVal);
    }

    int totalTime = 0;
    while (!pq.empty())
    {
        totalTime += pq.top() * pq.size();
        pq.pop();
    }

    cout<<totalTime;
}
*/
