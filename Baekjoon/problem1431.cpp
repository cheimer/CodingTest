/*
/*
 *  Link : https://www.acmicpc.net/problem/1431
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool IsFront(string& A, string& B)
{
    if (A.size() != B.size())
    {
        return A.size() < B.size();
    }
    
    int ANum = 0, BNum = 0;
    for (int i = 0; i < A.size(); i ++)
    {
        if (A[i] >= '0' && A[i] <= '9')
        {
            ANum += A[i] - '0';
        }
        if (B[i] >= '0' && B[i] <= '9')
        {
            BNum += B[i] - '0';
        }
    }
    if (ANum != BNum)
    {
        return ANum < BNum;
    }

    for (int i = 0; i < A.size(); i ++)
    {
        if (A[i] != B[i])
        {
            return A[i] < B[i];
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> serials(N, "");
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        serials[i] = tmp;
    }

    sort(serials.begin(), serials.end(), IsFront);

    for (int i = 0; i < N; i++)
    {
        cout << serials[i] << '\n';
    }
}
*/
