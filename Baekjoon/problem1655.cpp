/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include "iostream"
#include "queue"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, less<>> leftPQ;
    priority_queue<int, vector<int>, greater<>> rightPQ;
    
    int firstNum;
    cin >> firstNum;
    leftPQ.push(firstNum);
    cout << firstNum << '\n';

    for (int i = 1; i < N; i++)
    {
        int tmp;
        cin >> tmp;

        int currentMiddle;

        int leftTop = leftPQ.top();

        if (leftPQ.size() == rightPQ.size())
        {
            if (leftTop >= tmp)
            {
                leftPQ.push(tmp);
                currentMiddle = leftPQ.top();
            }
            else
            {
                rightPQ.push(tmp);
                currentMiddle = rightPQ.top();
            }
        }
        else if (leftPQ.size() > rightPQ.size())
        {
            if (leftTop >= tmp)
            {
                leftPQ.pop();
                leftPQ.push(tmp);
                
                rightPQ.push(leftTop);

                currentMiddle = leftPQ.top();
            }
            else
            {
                rightPQ.push(tmp);

                currentMiddle = leftPQ.top();
            }
        }
        else if (leftPQ.size() < rightPQ.size())
        {
            if (leftTop >= tmp)
            {
                leftPQ.push(tmp);

                currentMiddle = leftPQ.top();
            }
            else
            {
                rightPQ.push(tmp);
                leftPQ.push(rightPQ.top());
                rightPQ.pop();

                currentMiddle = leftPQ.top();
            }
        }

        cout << currentMiddle << '\n';
    }
    
}
*/
