/*
/*
 *  Link : https://www.acmicpc.net/problem/5397
 #1#

#include "iostream"
#include "list"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caseNum;
    cin >> caseNum;

    for (int i = 0; i < caseNum; i++)
    {
        string password;
        cin >> password;

        list<char> psList;
        list<char>::iterator iter = psList.begin();

        for (char psChar : password)
        {
            if (psChar == '<' || psChar == '>' || psChar == '-')
            {
                if (psList.empty())
                {
                    continue;
                }

                if (psChar == '<' && iter != psList.begin())
                {
                    --iter;
                }
                else if (psChar == '>' && iter != psList.end())
                {
                    ++iter;
                }
                else if (psChar == '-' && iter != psList.begin())
                {
                    --iter;
                    iter = psList.erase(iter);
                }
            }
            else
            {
                psList.insert(iter, psChar);
            }
        }

        for (char psChar : psList)
        {
            cout << psChar;
        }
        cout << '\n';
        
    }
    
}
*/
