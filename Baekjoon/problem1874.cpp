/*
/*
 *  Link : https://www.acmicpc.net/problem/1874
 #1#

#include "stack"
#include "vector"

#include "iostream"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> problem;
    for (int i = 0; i < N; i++)
    {
        int currentNum;
        cin >> currentNum;

        problem.push_back(currentNum);
        
    }
    
    stack<int> st;
    bool bIsClear = false;
    
    vector<char> vec;
    int problemIndex = 0;
    
    for (int i = 1; i <= N; i++)
    {
        if (problem[problemIndex] != i)
        {
            st.push(i);
            vec.push_back('+');
        }
        else
        {
            vec.push_back('+');
            while (true)
            {
                problemIndex++;
                vec.push_back('-');
                if (problemIndex >= problem.size() || st.empty())
                {
                    break;
                }
                
                if (problem[problemIndex] == st.top())
                {
                    st.pop();
                }
                else
                {
                    break;
                }
            }
        }
    }

    if (st.empty())
    {
        bIsClear = true;
    }

    if (bIsClear)
    {
        for (char c : vec)
        {
            cout<<c<<'\n';
        }
    }
    else
    {
        cout<<"NO";
    }
    
}
*/
