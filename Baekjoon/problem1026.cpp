/*
/*
 *  Link : https://www.acmicpc.net/problem/1026
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

    priority_queue<int, vector<int>, less<int>> minQue;
    priority_queue<int, vector<int>, greater<int>> maxQue;
    for (int i = 0; i < N; i++)
    {
        int ANum;
        cin >> ANum;
        minQue.push(ANum);
    }
    for (int i = 0; i < N; i++)
    {
        int BNum;
        cin >> BNum;
        maxQue.push(BNum);
    }

    int ans = 0;
    while (!minQue.empty())
    {
        ans += minQue.top() * maxQue.top();
        minQue.pop();
        maxQue.pop();
    }

    cout << ans;
}
*/
