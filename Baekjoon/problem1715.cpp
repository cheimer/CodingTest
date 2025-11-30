/*
/*
 *  Link : https://www.acmicpc.net/problem/1715
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

    priority_queue<int, vector<int>, greater<>> pq;
    
    for (int i = 0; i < N; i ++)
    {
        int tmp;
        cin >> tmp;

        pq.push(tmp);
    }

    int sum = 0;
    while (!pq.empty())
    {
        int firstTop = pq.top();
        pq.pop();

        if (pq.empty())
        {
            break;
        }
        else
        {
            int secondTop = pq.top();
            pq.pop();
            sum += firstTop + secondTop;
            pq.push(firstTop + secondTop);
        }
    }

    cout << sum;

}
*/
