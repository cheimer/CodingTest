/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include <algorithm>

#include "iostream"
#include "vector"

using namespace std;

/**
 * 1.1 -> 0, 12.31 -> 364
 #1#
int MonthDayToNum(int month, int day)
{
    int dayNum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int num = 0;
    for (int i = 1; i < month; i++)
    {
        num += dayNum[i];
    }

    num += day - 1;

    return num;
}

struct Node
{
    int startNum;
    int endNum;
};

bool SortRule(Node& a, Node& b)
{
    if (a.startNum != b.startNum)
    {
        return a.startNum < b.startNum;
    }
    else if (a.endNum != b.endNum)
    {
        return a.endNum > b.endNum;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    int minStartNum = MonthDayToNum(3, 1);
    int maxEndNum = MonthDayToNum(12, 1);

    vector<Node> nodes;

    for (int i = 0; i < num; i++)
    {
        int startMonth, startDay, endMonth, endDay;
        cin >> startMonth >> startDay >> endMonth >> endDay;

        int startNum = MonthDayToNum(startMonth, startDay);
        int endNum = MonthDayToNum(endMonth, endDay);

        if (startNum >= maxEndNum || endNum <= minStartNum) continue;

        Node numInfo;
        numInfo.startNum = max(startNum, minStartNum);
        numInfo.endNum = min(endNum, maxEndNum);

        nodes.push_back(numInfo);
        
    }

    sort(nodes.begin(), nodes.end(), SortRule);

    int currentNum = minStartNum;
    int flowerNum = 0;
    
    int currentIndex = 0;
    while (currentNum < maxEndNum)
    {
        if (currentIndex >= nodes.size())
        {
            cout<<0;
            return 0;
        }

        if (nodes[currentIndex].startNum > currentNum)
        {
            cout<<0;
            return 0;
        }

        int changeLen = 0;
        for (int i = currentIndex; i < nodes.size(); i++)
        {
            if (nodes[i].startNum > currentNum) break;

            nodes[i].startNum = currentNum;
            changeLen++;
        }

        sort(nodes.begin() + currentIndex, nodes.begin() + currentIndex + changeLen, SortRule);
        
        currentNum = nodes[currentIndex].endNum;
        flowerNum++;

        while (currentIndex < nodes.size())
        {
            if (nodes[currentIndex].endNum > currentNum) break;

            currentIndex++;
        }
    }

    cout<<flowerNum;
    
}
*/
