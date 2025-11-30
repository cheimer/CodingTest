/*
/*
 *  Link : https://www.acmicpc.net/problem/1822
 #1#

#include "iostream"
#include "queue"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    priority_queue<int, vector<int>, greater<int>> Apq;
    priority_queue<int, vector<int>, greater<int>> Bpq;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        Apq.push(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;

        Bpq.push(tmp);
    }

    priority_queue<int, vector<int>, greater<int>> ansPq;
    while (!Apq.empty())
    {
        int ATop = Apq.top();
        Apq.pop();

        bool bIsEqual = false;
        while (!Bpq.empty())
        {
            int BTop = Bpq.top();
            if (BTop < ATop)
            {
                Bpq.pop();
            }
            else if (BTop > ATop)
            {
                ansPq.push(ATop);
                break;
            }
            else if (BTop == ATop)
            {
                Bpq.pop();
                bIsEqual = true;
                break;
            }
        }

        if (Bpq.empty() && !bIsEqual)
        {
            ansPq.push(ATop);
        }
    }

    cout<<ansPq.size()<<'\n';

    while (!ansPq.empty())
    {
        cout << ansPq.top() << ' ';
        ansPq.pop();
    }
    
}
*/
