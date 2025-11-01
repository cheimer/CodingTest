/*
/*
 *  Link : https://www.acmicpc.net/problem/7785
 #1#

#include "iostream"
#include "set"
#include "string"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    set<string, greater<string>> nameSet;
    for (int i = 0; i < num; i++)
    {
        string name, act;
        cin >> name;
        cin >> act;

        if (act == "enter")
        {
            nameSet.emplace(name);
        }
        else
        {
            nameSet.erase(name);
        }
    }

    for (const string& name : nameSet)
    {
        cout<<name<<'\n';
    }
    
}
*/
