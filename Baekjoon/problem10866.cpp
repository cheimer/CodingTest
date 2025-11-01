/*
/*
 *  Link : https://www.acmicpc.net/problem/10866
 #1#

#include "iostream"
#include "deque"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    deque<int> deq;

    for (int i = 0; i < N; i++)
    {
        string order;
        cin >> order;

        if (order == "push_front")
        {
            int inputNum;
            cin >> inputNum;

            deq.push_front(inputNum);
        }
        else if (order == "push_back")
        {
            int inputNum;
            cin >> inputNum;

            deq.push_back(inputNum);
        }
        else if (order == "pop_front")
        {
            if (deq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if (order == "pop_back")
        {
            if (deq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if (order == "size")
        {
            cout << deq.size() << '\n';
        }
        else if (order == "empty")
        {
            if (deq.empty())
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (order == "front")
        {
            if (deq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << deq.front() << '\n';
            }
        }
        else if (order == "back")
        {
            if (deq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << deq.back() << '\n';
            }
        }
        
    }

    
    
}
*/
