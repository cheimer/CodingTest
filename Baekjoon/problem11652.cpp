/*
 *  Link : https://www.acmicpc.net/problem/11652
 */


/*
#include "iostream"
#include "unordered_map"
#include "limits.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<long long, int> cardMap;

    long long maxNumber = LONG_MAX;
    int maxNumCount = 1;

    for (int i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;

        if (cardMap.count(tmp) == 0)
        {
            cardMap.emplace(tmp, 1);
            if (maxNumCount == 1)
            {
                maxNumber = min(tmp, maxNumber);
            }
        }
        else
        {
            cardMap[tmp]++;
            if (cardMap[tmp] == maxNumCount)
            {
                maxNumber = min(tmp, maxNumber);
            }
            else if (cardMap[tmp] > maxNumCount)
            {
                maxNumber = tmp;
                maxNumCount = cardMap[tmp];
            }
        }
    }

    cout << maxNumber;
    
}
*/
