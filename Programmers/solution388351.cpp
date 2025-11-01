// Link : https://school.programmers.co.kr/learn/courses/30/lessons/388351

#include <iostream>
#include <vector>

using namespace std;

/*
schedules = 출근 희망 시각
timelogs = 일주일 돵안 출근한 시각
startday = 이벤트를 시작한 요일
answer = 상품 받을 직원 수

1 <= schedules.length <= 1000
700 <= schedules[i] <= 1100
1 <= timelogs.lenght <= 1000
timelogs[i].legnth = 7
1 <= startday <= 7
1 = monday
6, 7 not include

*/

bool TimeCheck(int schedule, int timeLog, int day)
{
    int currentDay = day > 7 ? day - 7 : day;
    if (currentDay == 6 || currentDay == 7) return true;
    
    if (schedule >= timeLog)
    {
        return true;
    }
    else
    {
        int min = schedule % 100;
        int limitTime = min >= 50 ? schedule + 50 : schedule + 10;

        return timeLog <= limitTime;
    }
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); i++)
    {
        int bIsSuccess = true;
        for (int j = 0; j < timelogs[i].size(); j++)
        {
            if (!TimeCheck(schedules[i], timelogs[i][j], startday + j))
            {
                bIsSuccess = false;
                break;
            }
        }
        answer = bIsSuccess ? answer + 1 : answer;
    }

    
    return answer;
}