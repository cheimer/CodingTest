/*
/*
 *  Link : https://www.acmicpc.net/problem/1406
 #1#

#include "iostream"
#include "list"
#include "string"

using namespace std;
//L D B P @
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    list<char> chList;
    for (char i : str)
    {
        chList.push_back(i);
    }
    list<char>::iterator iter = chList.end();
    
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string request;
        cin >> request;

        if (request[0] == 'L')
        {
            if (iter != chList.begin())
            {
                --iter;
            }
        }
        else if (request[0] == 'D')
        {
            if (iter != chList.end())
            {
                ++iter;
            }
        }
        else if (request[0] == 'B')
        {
            if (iter != chList.begin())
            {
                --iter;
                iter = chList.erase(iter);
            }
        }
        else if (request[0] == 'P')
        {
            char inputChar;
            cin >> inputChar;
            
            iter = chList.insert(iter, inputChar);
            ++iter;
        }
    }

    for (char ch : chList)
    {
        cout<<ch;
    }
    
}
*/
