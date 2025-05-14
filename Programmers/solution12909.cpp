/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/12909
 *
 * Solution : () 로 이루어진 문자열 인지
 *
 *  Str : 문자열
 *
 *  Str.Length <= 100000
 *  Str 은 (, ) 로만 이루어짐
 */

#include <string>
#include <stack>

using namespace std;

bool solution(string Str)
{
    stack<bool> StrStack;

    for (int i = 0; i < Str.length(); i++)
    {
        if (Str[i] == '(')
        {
            StrStack.push(true);
        }
        else if (Str[i] == ')')
        {
            if (StrStack.empty())
            {
                return false;
            }
            
            if (StrStack.top())
            {
                StrStack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (StrStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}