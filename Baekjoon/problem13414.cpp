/*
/*
 *  Link : https://www.acmicpc.net/problem/13414
 #1#

#include "iostream"
#include "map"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, L;
    cin >> K >> L;

    map<string, int> numMap;
    vector<string> numVec;
    for (int i = 0; i < L; i++)
    {
        string currentNum;
        cin >> currentNum;
        
        numVec.push_back(currentNum);

        if (numMap.count(currentNum) == 0)
        {
            numMap[currentNum] = 1;
        }
        else
        {
            numMap[currentNum]++;
        }
    }

    int currentInner = 0;
    for (string num : numVec)
    {
        if (numMap[num] == 1)
        {
            cout<<num<<'\n';
            currentInner++;

            if (currentInner >= K)
            {
                break;
            }
        }
        else
        {
            numMap[num]--;
        }
    }
    
}
*/
