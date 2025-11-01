/*
/*
 *  Link : https://www.acmicpc.net/problem/6603
 #1#

#include "iostream"
#include "vector"

using namespace std;

const int maxNum = 6;

void DFS(int currentIndex, vector<int>& listVec, const vector<int>& testVec)
{
    if (listVec.size() == maxNum)
    {
        for (int listNum : listVec)
        {
            cout << listNum << ' ';
        }
        cout<<'\n';
        return;
    }

    for (int i = currentIndex; i < testVec.size(); i++)
    {
        listVec.push_back(testVec[i]);
        DFS(i + 1, listVec, testVec);
        listVec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int testSize;
        cin >> testSize;
        if (testSize == 0)
        {
            break;
        }

        vector<int> testVec(testSize, 0);
        for (int i = 0; i < testSize; i++)
        {
            int num;
            cin >> num;
            testVec[i] = num;
        }
        
        vector<int> listVec;
        DFS(0, listVec, testVec);

        cout<<'\n';
    }
    
}
*/
