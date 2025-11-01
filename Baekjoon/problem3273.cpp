/*
/*
 *  Link : https://www.acmicpc.net/problem/3273
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    vector<int> arr;

    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    int compareNum;
    cin >> compareNum;

    sort(arr.begin(), arr.end());

    int startIndex = 0;
    int endIndex = num - 1;
    int answer = 0;

    while (startIndex < endIndex)
    {
        int currentNum = arr[startIndex] + arr[endIndex];

        if (currentNum == compareNum)
        {
            answer++;
            startIndex++;
            endIndex--;
        }
        else if (currentNum < compareNum)
        {
            startIndex++;
        }
        else if (currentNum > compareNum)
        {
            endIndex--;
        }
    }

    cout << answer;
}
*/
