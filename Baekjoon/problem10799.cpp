/*
/*
 *  Link : https://www.acmicpc.net/problem/10799
 #1#

#include "iostream"
#include "stack"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string qst;

    cin >> qst;
    stack<int> st;
    int answer = 0;

    for (int i = 0; i < qst.size(); i++)
    {
        if (qst[i] == '(')
        {
            if (qst[i + 1] == ')')
            {
                answer += st.size();
                i++;
            }
            else
            {
                st.push(0);
                answer++;
            }
        }
        else
        {
            st.pop();
        }
    }

    cout<<answer;
    
    
}
*/
