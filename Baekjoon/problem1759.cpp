/*
/*
 *  Link : https://www.acmicpc.net/problem/1759
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void DFS(int currentIndex, const int maxLen, const vector<char>& listVec, vector<char>& answerVec)
{
    if (answerVec.size() == maxLen)
    {
        int moNum = 0;
        int jaNum = 0;
        for (char answer : answerVec)
        {
            switch (answer)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                moNum++;
                break;
            default:
                jaNum++;
            }
        }

        if (moNum >= 1 && jaNum >= 2)
        {
            for (char answer : answerVec)
            {
                cout<<answer;
            }
            cout<<'\n';
        }
        
        return;
    }

    for (int i = currentIndex; i < listVec.size(); i++)
    {
        answerVec.push_back(listVec[i]);
        DFS(i + 1, maxLen, listVec, answerVec);
        answerVec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    cin >> L >> C;

    vector<char> listVec(C, 0);
    for (int i = 0; i < C; i++)
    {
        cin >> listVec[i];
    }

    sort(listVec.begin(), listVec.end());

    vector<char> answerVec;
    DFS(0, L, listVec, answerVec);
    
}
*/
