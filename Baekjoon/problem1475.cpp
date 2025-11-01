/*
/*
 *  Link : https://www.acmicpc.net/problem/2577
 #1#

#include "iostream"

using namespace std;

int arr[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n > 0)
    {
        int current = n % 10;
        arr[current]++;
        n /= 10;
    }

    bool bIsAddOne = (arr[6] + arr[9]) % 2 == 1;
    arr[6] = (arr[6] + arr[9]) / 2;
    arr[9] = arr[6];

    if (bIsAddOne)
    {
        arr[6]++;
        arr[9]++;
    }

    int maxNum = 0;

    for (int arrNum : arr)
    {
        maxNum = max(arrNum, maxNum);
    }

    cout << maxNum;
    
}
*/
