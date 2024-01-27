// https://school.programmers.co.kr/learn/courses/30/lessons/140107

// Question
/*
���� ����
��ǥ����� �����ϴ� ������ x��� y���� �����ϴ� 2���� ��ǥ��鿡 ���� �����鼭 ��� �ֽ��ϴ�. ������ �� ���� ���� k, d�� �־��� �� ������ ���� ���� ������ �մϴ�.

����(0, 0)���κ��� x�� �������� a*k(a = 0, 1, 2, 3 ...), y�� �������� b*k(b = 0, 1, 2, 3 ...)��ŭ ������ ��ġ�� ���� ����ϴ�.
������ �Ÿ��� d�� �Ѵ� ��ġ���� ���� ���� �ʽ��ϴ�.
���� ���, k�� 2, d�� 4�� ��쿡�� (0, 0), (0, 2), (0, 4), (2, 0), (2, 2), (4, 0) ��ġ�� ���� ��� �� 6���� ���� ����ϴ�.

���� k�� �������� �Ÿ��� ��Ÿ���� ���� d�� �־����� ��, ���� �� �� �� �������� return �ϴ� solution �Լ��� �ϼ��ϼ���.

���ѻ���
1 �� k �� 1,000,000
1 �� d �� 1,000,000
����� ��
k	d	result
2	4	6
1	5	26
����� �� ����
����� �� #1

������ ���ÿ� �����ϴ�.
����� �� #2

(0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (3, 0), (3, 1), (3, 2), (3, 3), (3, 4), (4, 0), (4, 1), (4, 2), (4, 3), (5, 0) ��ġ�� ���� ���� �� ������, �� 26�� �Դϴ�.
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) {

    if(k > d)
        return 1;

    long long answer = 0;

    long long distance = d;
    long long yPos = distance - distance % k;
    for(long long xPos = 0; xPos <= distance; xPos += k)
    {
        while(yPos >= 0)
        {
            if(xPos * xPos + yPos * yPos > distance*distance)
            {
                yPos -= k;
            }
            else
                break;
        }
        answer += yPos / k + 1;
    }


    return answer;
}