/*
/*
 *  Link : https://www.acmicpc.net/problem/2493
 #1#

#include <stack>

#include "iostream"
#include "stack"
#include "vector"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    int firstNum;
    stack<pair<int, int>> st;
    vector<int> answer;
    
    cin >> firstNum;
    st.emplace(firstNum, 0);
    answer.push_back(-1);
    
    for (int i = 1; i < num; i++)
    {
        int currentNum;
        cin >> currentNum;

        while (!st.empty())
        {
            pair<int, int> beforeValue = st.top();
            if (beforeValue.first < currentNum)
            {
                st.pop();
            }
            else if (beforeValue.first >= currentNum)
            {
                st.emplace(currentNum, i);
                answer.push_back(beforeValue.second);
                break;
            }
        }

        if (st.empty())
        {
            st.emplace(currentNum, i);
            answer.push_back(-1);
        }
    }

    for (int i = 0; i < num; i++)
    {
        cout << answer[i] + 1 << ' ';
    }

    return 0;

}
*/
