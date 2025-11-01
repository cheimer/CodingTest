/*
/*
 *  Link : https://www.acmicpc.net/problem/3015
 *  핵심 : 같은 경우 케이스 처리 -> 단순히 넣으면 시간 초과 -> pair로 연속된 값을 하나로 처리한 후 answer에 더할 때의 정리
 #1#

#include <stack>

#include "iostream"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    long long answer = 0;
    stack<pair<long long, int>> st;
    
    for (int i = 0; i < N; i++)
    {
        long long value;
        cin >> value;

        long long equalNum = 1;
        while (!st.empty())
        {
            long long top = st.top().first;

            if (top > value)
            {
                answer++;
            }
            else
            {
                answer += st.top().second;
            }
            
            if (top < value)
            {
                st.pop();
            }
            else if (top == value)
            {
                equalNum = st.top().second + 1;
                st.pop();
            }
            else if (top > value)
            {
                break;
            }
        }
        
        st.emplace(value, equalNum);
    }

    cout<<answer;
}
*/
