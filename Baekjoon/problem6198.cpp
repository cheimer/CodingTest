/*
/*
 *  Link : https://www.acmicpc.net/problem/6198
 *  핵심 : 자신을 볼 수 있는 갯수를 세는 것.
 #1#


#include "iostream"
#include "stack"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long answer = 0;
    stack<int> st;
    
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;

        while (!st.empty())
        {
            if (st.top() <= value)
            {
                st.pop();
            }
            else
            {
                break;
            }
        }
        answer += static_cast<long long>(st.size());
        
        st.push(value);
    }

    cout<<answer;
    
}
*/
