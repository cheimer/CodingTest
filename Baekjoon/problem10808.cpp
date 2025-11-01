/*
/*
 *  Link : https://www.acmicpc.net/problem/10808
 #1#

#include "iostream"
#include "string"

using namespace std;

int arr[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (char i : s)
    {
        int alIndex = i - 'a';
        arr[alIndex] += 1;
    }

    for (int i : arr)
    {
        cout << i << ' ';
    }
    
}
*/
