/*
/*
 *  Link : https://www.acmicpc.net/problem/19583
 #1#

#include "iostream"
#include "string"
#include "map"

using namespace std;

int TimeStringToInt(const string& timeStr)
{
    int hour = stoi(timeStr.substr(0, 2));
    int min = stoi(timeStr.substr(3, 2));

    return hour * 60 + min;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string startStr, middleStr, endStr;
    cin >> startStr >> middleStr >> endStr;
    
    int startTime = TimeStringToInt(startStr);
    int middleTime = TimeStringToInt(middleStr);
    int endTime = TimeStringToInt(endStr);

    map<string, bool> perInfos;
    int checkNum = 0;
    while (true)
    {
        string timeStr, nameStr;
        cin >> timeStr >> nameStr;
        if (cin.eof()) break;

        int currentTime = TimeStringToInt(timeStr);

        if (currentTime <= startTime)
        {
            perInfos[nameStr] = false;
        }
        else if (currentTime >= middleTime && currentTime <= endTime)
        {
            if (perInfos.count(nameStr) > 0 && !perInfos[nameStr])
            {
                perInfos[nameStr] = true;
                checkNum++;
            }
        }
        
    }

    cout<<checkNum;
    
}
*/
