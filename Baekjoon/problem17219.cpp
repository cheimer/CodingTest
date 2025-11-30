/*
/*
 *  Link : https://www.acmicpc.net/problem/17219
 #1#

#include "iostream"
#include "map"
#include "string"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<string, string> sitePswMap;

    for (int i = 0; i < N; i++)
    {
        string site, psw;
        cin >> site >> psw;
        sitePswMap[site] = psw;
    }

    for (int i = 0; i < M; i++)
    {
        string findSite;
        cin >> findSite;

        cout << sitePswMap[findSite] << '\n';
    }
    
}
*/
