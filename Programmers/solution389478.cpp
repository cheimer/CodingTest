// Link : https://school.programmers.co.kr/learn/courses/30/lessons/389478

/*
 * 2 <= n <= 100: 상자 갯수
 * 1 <= w <= 10: 가로 길이
 * num : 꺼내려는 상자
*/

#include <vector>

using namespace std;

int boxIndex[110][110] = {};

int solution(int n, int w, int num) {

    int line = 0;
    pair<int, int> numIndex;
    for (int i = 1; i <= n; )
    {
        for (int j = 0; j < w; j++)
        {
            if (i > n) break;

            if (i == num)
            {
                numIndex.first = line;
                numIndex.second = j;
            }
            boxIndex[line][j] = i;
            i++;
        }
        line++;
        for (int j = w - 1; j >= 0; j--)
        {
            if (i > n) break;
            
            if (i == num)
            {
                numIndex.first = line;
                numIndex.second = j;
            }
            boxIndex[line][j] = i;
            i++;
        }
        line++;
    }

    
    int answer = 0;

    for (int i = numIndex.first; i < 110; i++)
    {
        if (boxIndex[i][numIndex.second] != 0)
        {
            answer++;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}