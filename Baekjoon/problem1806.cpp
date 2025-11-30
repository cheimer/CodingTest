/*
/*
 *  Link : https://www.acmicpc.net/problem/1806
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

#define LEN_MAX 123456789

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    vector<int> numVec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numVec[i];
    }

    int firstIndex = 0, secondIndex = 0;
    int minLen = LEN_MAX;
    int currentSum = 0;

    while (secondIndex < numVec.size())
    {
        currentSum += numVec[secondIndex];
        secondIndex++;
        
        if (currentSum >= S)
        {
            while (currentSum >= S)
            {
                currentSum -= numVec[firstIndex];
                firstIndex++;
            }
            
            minLen = min(minLen, secondIndex - firstIndex + 1);

        }
    }

    if (minLen == LEN_MAX)
    {
        minLen = 0;
    }
    cout << minLen;
    
}
*/
