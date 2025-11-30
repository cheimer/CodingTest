/*
/*
 *  Link : https://www.acmicpc.net/problem/2217
 #1#

#include "iostream"
#include "queue"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int maxWeight = 0;
    while(!pq.empty())
    {
        int currentNum = pq.top();

        maxWeight = max(maxWeight, currentNum * static_cast<int>(pq.size()));
        
        pq.pop();
    }

    cout << maxWeight;
}
*/
