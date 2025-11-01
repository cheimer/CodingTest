/*
/*
 *  Link : https://www.acmicpc.net/problem/1158
 #1#

#include <list>

#include "iostream"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    list<int> personList;
    for (int i = 1; i <= N; i++)
    {
        personList.push_back(i);
    }

    list<int>::iterator iter = personList.begin();
    int currentNum = 1;

    cout<<'<';
    while (personList.size() > 1)
    {
        while (currentNum < K)
        {
            currentNum++;
            ++iter;
            if (iter == personList.end())
            {
                iter = personList.begin();
            }
        }
        currentNum = 0;

        cout << *iter << ", ";
        iter = personList.erase(iter);
        if (iter == personList.end())
        {
            iter = personList.begin();
        }
        currentNum++;
    }

    cout << *iter << '>';
    
}
*/
