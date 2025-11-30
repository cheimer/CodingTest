/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include "iostream"
#include "string"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;

    cin >> str;

    int startIndex = 0;
    bool bIsPlus = true;
    int answer = 0;
    
    for (int currentIndex = 1; ; currentIndex++)
    {
        if (currentIndex >= str.size() - 1)
        {
            int currentNum = stoi(str.substr(startIndex));
            answer += bIsPlus ? currentNum : -currentNum;
            break;
        }
        
        if (str[currentIndex] == '+' || str[currentIndex] == '-')
        {
            int currentNum = stoi(str.substr(startIndex, currentIndex - startIndex));
            answer += bIsPlus ? currentNum : -currentNum;
            startIndex = currentIndex + 1;

            if (bIsPlus && str[currentIndex] == '-')
            {
                bIsPlus = false;
            }
        }
    }

    cout << answer;
    
}
*/
