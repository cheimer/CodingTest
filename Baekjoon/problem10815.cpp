/*
/*
 *  Link : https://www.acmicpc.net/problem/10815
 #1#

#include "iostream"
#include "map"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<int, bool> m;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        m[tmp] = true;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;

        if (m.count(tmp) > 0)
        {
            cout<< "1 ";
        }
        else
        {
            cout<< "0 ";
        }
    }
    
}
*/
