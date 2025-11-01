/*
/*
 *  Link : https://www.acmicpc.net/problem/2577
 #1#

#include "iostream"
#include "string"

int arr[10];

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int num = a * b * c;

    while (num > 0)
    {
        int lastNum = num % 10;
        arr[lastNum]++;
        num /= 10;
    }

    for (int i : arr)
    {
        cout << i << '\n';
    }
    
}
*/
