/*
/*
 *  Link : https://www.acmicpc.net/problem/
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

    for (int i = 0; i < N * N; i++)
    {
        int tmp;
        cin >> tmp;

        if (pq.size() < N)
        {
            pq.push(tmp);
        }
        else
        {
            if (pq.top() < tmp)
            {
                pq.pop();
                pq.push(tmp);
            }
        }
    }

    cout << pq.top();
}
*/
