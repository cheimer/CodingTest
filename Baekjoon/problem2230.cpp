/*
/*
 *  Link : https://www.acmicpc.net/problem/2230
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<int> numVec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> numVec[i];
    }

    sort(numVec.begin(), numVec.end());

    int minDif = 2000000001;
    int firstIndex = 0;
    int secondIndex = 0;

    while (secondIndex < numVec.size())
    {
        int currentDif = numVec[secondIndex] - numVec[firstIndex];

        if (currentDif < M)
        {
            secondIndex++;
        }
        else if (currentDif > M)
        {
            firstIndex++;
            minDif = min(currentDif, minDif);
        }
        else if (currentDif == M)
        {
            minDif = M;
            break;
        }
    }

    cout << minDif;
    
}
*/
