/*
/*
 *  Link : https://www.acmicpc.net/problem/1644
 #1#

#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

bool IsPrime(int n)
{
    if (n <= 1) return false;
    
    int sqN = sqrt(n);
    for (int i = 2; i <= sqN; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> primeVec;

    for (int i = 2; i <= N; i++)
    {
        if (IsPrime(i))
        {
            primeVec.push_back(i);
        }
    }
    
    int firstIndex = 0, secondIndex = 0;
    int currentSum = 0;
    int count = 0;

    while (secondIndex < primeVec.size())
    {
        currentSum += primeVec[secondIndex];
        secondIndex++;
        
        if (currentSum == N)
        {
            count++;
            currentSum -= primeVec[firstIndex];
            firstIndex++;
        }
        else if (currentSum > N)
        {
            while (currentSum > N)
            {
                currentSum -= primeVec[firstIndex];
                firstIndex++;
            }

            if (currentSum == N)
            {
                count++;
                currentSum -= primeVec[firstIndex];
                firstIndex++;
            }
        }
    }

    cout<<count;
}
*/
