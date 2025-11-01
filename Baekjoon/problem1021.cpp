/*
/*
 *  Link : https://www.acmicpc.net/problem/1021
#1#

#include "iostream"
#include "deque"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queSize;
    cin >> queSize;

    deque<int> deq;
    for (int i = 1; i <= queSize; i++)
    {
        deq.push_back(i);
    }
    
    int findSize;
    cin >> findSize;

    int answer = 0;
    for (int i = 0; i < findSize; i++)
    {
        int findNum;
        cin >> findNum;

        if (deq.front() == findNum)
        {
            deq.pop_front();
            continue;
        }
        
        deque<int> leftDeq = deq;
        deque<int> rightDeq = deq;

        while (leftDeq.front() != findNum && rightDeq.front() != findNum)
        {
            leftDeq.push_back(leftDeq.front());
            leftDeq.pop_front();
            
            rightDeq.push_front(rightDeq.back());
            rightDeq.pop_back();
            answer++;
        }

        if (leftDeq.front() == findNum)
        {
            deq = leftDeq;
        }
        else
        {
            deq = rightDeq;
        }
        deq.pop_front();
        
    }

    cout << answer;
    
}
*/
