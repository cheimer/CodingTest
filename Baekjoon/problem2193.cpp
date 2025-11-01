/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include "iostream"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);

    for (int i = 3; i <= N; i++)
    {
        vec.push_back(vec[i - 2] + vec[i - 1]);
    }

    cout<<vec[N];
}
*/
