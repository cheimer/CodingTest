/*
* Link : https://school.programmers.co.kr/learn/courses/30/lessons/42576
 * 
 * 마라톤 선수 이름 배열 : Participant 
 * 완주 선수 이름 배열 : Completion
 * 완주못한 선수 이름 String : Answer
 * 
 * 조건 : 1 <= Participant.Length() <= 100000
 *  Completion.Length() = Participant.Length() - 1
 *  1 <= Participant[i].Length() <= 20
 *  동명이인 가능
 */

#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> Participant, vector<string> Completion)
{
    map<string, int> NameNums;

    for (string& Name : Participant)
    {
        if (NameNums.count(Name) == 0)
        {
            NameNums.insert(make_pair(Name, 1));
        }
        else
        {
            NameNums[Name]++;
        }
    }
    
    string answer;
    for (string& Name : Completion)
    {
        if (NameNums.count(Name) > 0)
        {
            NameNums[Name]--;
        }
        else
        {
            answer = "Error";
            break;
        }
    }
    
    for (auto NameNum : NameNums)
    {
        if (NameNum.second != 0)
        {
            answer = NameNum.first;
            break;
        }
    }
    
    return answer;
}
