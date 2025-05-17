/*
 * TODO: Not Solved
 * Error Ex : 4 * 4 - 4 / 4
 * 현재 한단계씩 진행함 -> (((4 * 4) - 4) / 4) 으로 진행됨
 * 
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42895
 *
 * Solution : N과 사칙연산만으로 원하는 숫자를 표현하는 최소의 수
 *
 *  N : 주어진 수
 *  number : 원하는 수
 *
 *  1 <= N <= 9
 *  1 <= number <= 32000
 *
 *  나누기에서 나머지는 무시
 *  최소값 > 8 이라면 -1을 리턴
 */

#include <iostream>
#include <queue>

using namespace std;

int solution(int N, int number)
{
    int VisitedNum[32001 * 9] = {};

    queue<int> Sequence;
    Sequence.push(N);
    VisitedNum[N] = 1;

    while (true)
    {
        int CurrentValue = Sequence.front();
        int CurrentVisited = VisitedNum[CurrentValue];
        Sequence.pop();
        cout << CurrentVisited << ", "<<CurrentValue << '\n';

        if (CurrentVisited > 8)
        {
            return -1;
        }

        if (CurrentValue == number)
        {
            return CurrentVisited;
        }
        
        int PlusValue = CurrentValue + N;
        if (PlusValue <= 32001 * 9 && VisitedNum[PlusValue] == 0)
        {
            Sequence.push(PlusValue);
            VisitedNum[PlusValue] = CurrentVisited + 1;
        }

        int MinusValue = CurrentValue - N;
        if (MinusValue >= 0 && VisitedNum[MinusValue] == 0)
        {
            Sequence.push(MinusValue);
            VisitedNum[MinusValue] = CurrentVisited + 1;
        }

        int MinusReverseValue = N - CurrentValue;
        if (MinusReverseValue >= 0 && VisitedNum[MinusReverseValue] == 0)
        {
            Sequence.push(MinusReverseValue);
            VisitedNum[MinusReverseValue] = CurrentVisited + 1;
        }

        int MulValue = CurrentValue * N;
        if (MulValue <= 32001 * 9 && VisitedNum[MulValue] == 0)
        {
            Sequence.push(MulValue);
            VisitedNum[MulValue] = CurrentVisited + 1;
        }
        
        int DivValue = CurrentValue / N;
        if (DivValue >= 0 && VisitedNum[DivValue] == 0)
        {
            Sequence.push(DivValue);
            VisitedNum[DivValue] = CurrentVisited + 1;
        }

        if (CurrentValue != 0)
        {
            int DivReverseValue = N / CurrentValue;
            if (DivReverseValue >= 0 && VisitedNum[DivReverseValue] == 0)
            {
                Sequence.push(DivReverseValue);
                VisitedNum[DivReverseValue] = CurrentVisited + 1;
            }
        }

        int ValueValue = CurrentValue * 10 + N;
        if (ValueValue <= 32001 * 9 && VisitedNum[ValueValue] == 0)
        {
            Sequence.push(ValueValue);
            VisitedNum[ValueValue] = CurrentVisited + 1;
        }
    }
}
