// https://school.programmers.co.kr/learn/courses/30/lessons/152996

// Question
/*
���� ����
��� ���� �����Ϳ��� �üҰ� �ϳ� ��ġ�Ǿ� �ֽ��ϴ�. �� �üҴ� �߽����κ��� 2(m), 3(m), 4(m) �Ÿ��� ������ �¼��� �ϳ��� �ֽ��ϴ�.
�� �üҸ� �� ���� ���� ���� ź�ٰ� �� ��, �üҰ� ������ ���¿��� ������ ���� �üҿ� �ɸ��� ��ũ�� ũ�Ⱑ ���� ���Ǿ� ������ ������ �̷� �� �ִٸ� �� �� ����� �ü� ¦���̶�� �մϴ�. ��, ž���� ����� ���Կ� �ü� ��� �¼� ���� �Ÿ��� ���� ���� �� ���ٸ� �ü� ¦���̶�� �� �� �ֽ��ϴ�.
������� ������ ��� weights�� �־��� ��, �ü� ¦���� �� �� �����ϴ��� ���Ͽ� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���� ����
2 �� weights�� ���� �� 100,000
100 �� weights[i] �� 1,000
������ ������ N(����)���� �־����ϴ�.
�����Դ� ��� �����Դϴ�.
����� ��
weights	result
[100,180,360,100,270]	4
����� �� ����
{100, 100} �� ���� ���� �Ÿ��� ���ֺ��� ������ ������ �̷�ϴ�.
{180, 360} �� ���� 4(m), 2(m) �Ÿ��� ���ֺ��� ������ ������ �̷�ϴ�.
{180, 270} �� ���� 3(m), 2(m) �Ÿ��� ���ֺ��� ������ ������ �̷�ϴ�.
{270, 360} �� ���� 4(m), 3(m) �Ÿ��� ���ֺ��� ������ ������ �̷�ϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long solution(vector<int> weights) {

    sort(weights.begin(), weights.end());

    map<int, int> weightNum;
    for (int weight : weights)
    {
        if(weightNum.count(weight) == 0)
        {
            weightNum[weight] = 1;
        }
        else
        {
            weightNum[weight]++;
        }
    }

    long long answer = 0;
    for (int weight : weights)
    {
        weightNum[weight]--;

        if(weightNum.count(weight) != 0)
        {
            answer += weightNum[weight];
        }
        if(weight % 3 == 0 && weightNum.count(weight * 4 / 3) != 0)
        {
            answer += weightNum[weight * 4 / 3];
        }
        if(weight % 2 == 0 && weightNum.count(weight * 3 / 2) != 0)
        {
            answer += weightNum[weight * 3 / 2];
        }if(weightNum.count(weight * 2) != 0)
        {
            answer += weightNum[weight * 2];
        }
    }

    return answer;
}