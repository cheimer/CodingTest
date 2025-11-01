// Link : https://school.programmers.co.kr/learn/courses/30/lessons/389481

/*
 *   n : 주문 넘버
 *   bans : 밴 주문
 *   1 <= n <= 10^15
 *   1 <= bans <= 300000
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

const int ALPHA_TO_INT = 96;

bool SortRule(string a, string b)
{
    if (a.length() < b.length()) return true;
    else if (a.length() > b.length()) return false;
    else
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] < b[i]) return true;
            else if (a[i] > b[i]) return false;
        }
    }

    return true;
}

string solution(long long n, vector<string> bans) {

    long long numValues[11];
    for (int i = 0; i < 11; i++)
    {
        numValues[i] = pow<long long>(26, 10 -i);
    }
    
    sort(bans.begin(), bans.end(), SortRule);

    for (auto ban : bans)
    {
        long long sum = 0;
        for (int i = 0; i < ban.length(); i++)
        {
            long long num = ban[i] - ALPHA_TO_INT ;
            sum += num * numValues[i - ban.length() + 11];
        }
        if (sum <= n)
        {
            n++;
        }
        else
        {
            break;
        }
    }
    
    string reverseAnswer = "";
    string answer = "";
    while (n > 0)
    {
        long long value = n % 26;
        if (value == 0)
        {
            value = 26;
            n -= 26;
        }
        
        char ch = (char)(value + ALPHA_TO_INT);

        reverseAnswer += ch;
        
        n /= 26;
    }

    for (int i = reverseAnswer.length() - 1; i >= 0; i--)
    {
        answer += reverseAnswer[i];
    }
    
    return answer;
}