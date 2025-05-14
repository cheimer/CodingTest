/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42746
 * 
 * Solution : 정수를 이어 붙일 때 가장 큰 수
 *
 * numbers : 정수 담긴 배열
 *
 * 1 <= numbers.length() <= 100000
 * 0 <= numbers[i] <= 1000
 */

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool FindBigNumWhenCompose(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        return num1 > num2;
    }
    
    int CachedNum1 = num1;
    int Num1Len = 0;
    while (CachedNum1 != 0)
    {
        CachedNum1 /= 10;
        Num1Len++;
    }
    
    int CachedNum2 = num2;
    int Num2Len = 0;
    while (CachedNum2 != 0)
    {
        CachedNum2 /= 10;
        Num2Len++;
    }

    if (Num1Len != Num2Len)
    {
        int Num1ComposeNum2 = num1 * pow(10, Num2Len) + num2;
        int Num2ComposeNum1 = num2 * pow(10, Num1Len) + num1;
        
        return Num1ComposeNum2 > Num2ComposeNum1;
    }
    else
    {
        return num1 > num2;
    }
}

string solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end(), FindBigNumWhenCompose);
    
    if (numbers[0] == 0)
    {
        return "0";
    }
    
    string answer = "";
    for (int number : numbers)
    {
        answer += to_string(number);
    }
    
    return answer;
}

/*
string solution(vector<int> numbers)
{
    string answer = "";

    vector<pair<double, int>> arr;

    for (int i = 0; i < numbers.size(); i++)
    {
        double num = numbers[i];

        if (num == 0)
            ;
        else if (num == 1000)
            num = 1;
        else if (num >= 100 && num < 1000)
            num += num/1000;
        else if (num >= 10 && num < 100)
            num *= 10.1;
        else if (num >= 0 && num < 10)
            num *= 111.1;

        arr.push_back(pair<double, int>(num, i));
    }
    sort(arr.begin(), arr.end(), greater<pair<double, int>>());

    for (int i = 0; i < arr.size(); i++)
        answer += to_string(numbers[arr[i].second]);

    int k = answer.size() - 1;
    for (int i = 0; i < k; i++)
    {
        if (answer[0] == '0')
            answer.erase(answer.begin());
        else
            break;
    }

    return answer; 
}
*/
