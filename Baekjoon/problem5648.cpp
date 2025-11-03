/*
/*
 *  Link : https://www.acmicpc.net/problem/5648
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long inputVal;
        cin >> inputVal;

        long long arrayVal = 0;

        while (inputVal > 0)
        {
            arrayVal *= 10;
            arrayVal += inputVal % 10;
            inputVal /= 10;
        }

        arr.push_back(arrayVal);
    }

    sort(arr.begin(), arr.end());

    for (long long arrVal : arr)
    {
        cout << arrVal << '\n';
    }
}
*/
