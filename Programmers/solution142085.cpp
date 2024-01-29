// https://school.programmers.co.kr/learn/courses/30/lessons/142085

// Question
/*
���� ����
��ȣ�� ���� ���潺 ���ӿ� ǫ ���� �ֽ��ϴ�. ���潺 ������ ��ȣ�� ������ ���� n������ ���ӵǴ� ���� ������ ������� ���� �����Դϴ�. ���潺 ������ ������ ���� ��Ģ���� ����˴ϴ�.

��ȣ�� ó���� ���� n���� ������ �ֽ��ϴ�.
�� ���帶�� enemy[i]������ ���� �����մϴ�.
���� ���� �� enemy[i]�� ��ŭ �Ҹ��Ͽ� enemy[i]������ ���� ���� �� �ֽ��ϴ�.
���� ��� ���� ���簡 7���̰�, ���� ���� 2������ ���, ���� ���带 ������ 7 - 2 = 5���� ���簡 �����ϴ�.
���� ������ ������ ���� ������ ���� ���� �� ������ ������ ����˴ϴ�.
���ӿ��� �������̶�� ��ų�� ������, �������� ����ϸ� ������ �Ҹ���� �� ������ ������ ���� �� �ֽ��ϴ�.
�������� �ִ� k�� ����� �� �ֽ��ϴ�.
��ȣ�� �������� ������ �ñ⿡ ����Ͽ� �ִ��� ���� ���带 �����ϰ� �ͽ��ϴ�.

��ȣ�� ó�� ������ �ִ� ������ �� n, ��� ������ �������� Ƚ�� k, �� ���帶�� �����ؿ��� ���� ���� ������� ��� ���� �迭 enemy�� �Ű������� �־����ϴ�. ��ȣ�� �� ������� ���� �� �ִ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� n �� 1,000,000,000
1 �� k �� 500,000
1 �� enemy�� ���� �� 1,000,000
1 �� enemy[i] �� 1,000,000
enemy[i]���� i + 1 ���忡�� �����ؿ��� ���� ���� ����ֽ��ϴ�.
��� ���带 ���� �� �ִ� ��쿡�� enemy[i]�� ���̸� return ���ּ���.
����� ��
n	k	enemy	result
7	3	[4, 2, 4, 5, 3, 3, 1]	5
2	4	[3, 3, 3, 3]	4
����� �� ����
����� ��#1

1, 3, 5 ������ ������ ���������� ���Ƴ���, 2, 4 ���忡 ���� ���縦 2��, 5�� �Ҹ��ϸ� 5������� ������ ���� �� �ֽ��ϴ�. ��, 1, 3, 4��° ������ ���������� ���Ƴ���, 2, 5 ��° ���ݿ� ���� ���縦 2��, 3�� �Ҹ��Ͽ� 5������� ������ ���� �� �ֽ��ϴ�. �׺��� ���� ���带 ���� ����� �����Ƿ� 5�� return �մϴ�.
����� ��#2

��ȣ�� ��� ���ݿ� �������� ����Ͽ� 4������� ���� �� �ֽ��ϴ�.
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {

    if(enemy.size() <= k)
        return enemy.size();

    priority_queue<int, vector<int>, greater<int>> usingKEnemy;
    int answer = 0;
    long long armyNum = n;

    for(int enemyNum : enemy)
    {
        if(k > 0)
        {
            usingKEnemy.push(enemyNum);
            answer++;
            k--;
            continue;
        }

        if(armyNum >= enemyNum)
        {
            if(enemyNum > usingKEnemy.top())
            {
                armyNum -= usingKEnemy.top();
                usingKEnemy.pop();
                usingKEnemy.push(enemyNum);
                answer++;
            }
            else
            {
                armyNum -= enemyNum;
                answer++;
            }
        }
        else
        {
            if(enemyNum > usingKEnemy.top() && armyNum - usingKEnemy.top() >= 0)
            {
                armyNum -= usingKEnemy.top();
                usingKEnemy.pop();
                usingKEnemy.push(enemyNum);
                answer++;
            }
            else
                return answer;
        }
    }

    return answer;
}