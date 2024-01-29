// https://school.programmers.co.kr/learn/courses/30/lessons/172927

// Question
/*
���� ����
������ ��̷� ���꿡�� ������ ĳ���� �մϴ�. ������ ���̾Ƹ�� ���, ö ���, �� ��̸� ���� 0������ 5������ ������ ������, ��̷� ������ Ķ ���� �Ƿε��� �Ҹ�˴ϴ�. �� ��̷� ������ Ķ ���� �Ƿε��� �Ʒ� ǥ�� �����ϴ�.

image

���� ���, ö ��̴� ���̾Ƹ�带 Ķ �� �Ƿε� 5�� �Ҹ�Ǹ�, ö�� ���� Ķ���� �Ƿε��� 1�� �Ҹ�˴ϴ�. �� ��̴� ������ ������� ���� 5���� ĵ �Ŀ��� �� �̻� ����� �� �����ϴ�.

������ ������ ���� ��Ģ�� ��Ű�鼭 �ּ����� �Ƿε��� ������ ĳ���� �մϴ�.

����� �� �ִ� ����� �ƹ��ų� �ϳ��� ������ ������ ĸ�ϴ�.
�� �� ����ϱ� ������ ��̴� ����� �� ���� ������ ����մϴ�.
������ �־��� ������θ� Ķ �� �ֽ��ϴ�.
���꿡 �ִ� ��� ������ ĳ�ų�, �� ����� ��̰� ���� ������ ������ ĸ�ϴ�.
��, ��̸� �ϳ� �����ؼ� ���� 5���� �������� ĳ��, ���� ��̸� �����ؼ� ���� 5���� �������� ĳ�� ������ �ݺ��ϸ�, �� ����� ��̰� ���ų� ���꿡 �ִ� ��� ������ Ķ ������ ������ �ݺ��ϸ� �˴ϴ�.

������ ���� �ִ� ����� ������ ��Ÿ���� ���� �迭 picks�� �������� ������ ��Ÿ���� ���ڿ� �迭 minerals�� �Ű������� �־��� ��, ������ �۾��� ��������� �ʿ��� �ּ����� �Ƿε��� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
picks�� [dia, iron, stone]�� ���� ������ �̷���� �ֽ��ϴ�.
0 �� dia, iron, stone �� 5
dia�� ���̾Ƹ�� ����� ���� �ǹ��մϴ�.
iron�� ö ����� ���� �ǹ��մϴ�.
stone�� �� ����� ���� �ǹ��մϴ�.
��̴� �ּ� 1�� �̻� ������ �ֽ��ϴ�.
5 �� minerals�� ���� �� 50
minerals�� ���� 3���� ���ڿ��� �̷���� ������ ������ �ǹ̴� ������ �����ϴ�.
diamond : ���̾Ƹ��
iron : ö
stone : ��
����� ��
picks	minerals	result
[1, 3, 2]	["diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"]	12
[0, 1, 1]	["diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"]	50
����� �� ����
����� �� #1

���̾Ƹ�� ��̷� �տ� �ټ� ������ ĳ�� ö ��̷� ���� ���̾Ƹ��, ö, ���� 1���� ĳ�� 12(1 + 1 + 1 + 1+ 1 + 5 + 1 + 1)�� �Ƿε��� Ķ �� ������ �̶��� �ּҰ��Դϴ�.

����� �� #2

ö ��̷� ���̾Ƹ�� 5���� ĳ�� �� ��̰� ö 5���� ĳ�� 50�� �Ƿε��� Ķ �� ������, �̶��� �ּҰ��Դϴ�.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {

    int pickNum = picks[0] + picks[1] + picks[2];
    int sum[10][4]; fill_n(&sum[0][0], 10 * 4, 0);

    int fiveTimes = 0;
    for(string mineral : minerals)
    {
        if(fiveTimes / 5 >= pickNum)
            break;

        if(mineral == "diamond")
        {
            sum[fiveTimes / 5][0] += 25;
            sum[fiveTimes / 5][1] ++;
        }
        else if(mineral == "iron")
        {
            sum[fiveTimes / 5][0] += 5;
            sum[fiveTimes / 5][2] ++;
        }
        else if(mineral == "stone")
        {
            sum[fiveTimes / 5][0] += 1;
            sum[fiveTimes / 5][3] ++;
        }

        fiveTimes++;
    }
    priority_queue<pair<int, int*>> mineralSum;
    for (int i = 0; i < 10; i++)
    {
        if(sum[i][0] == 0)
            break;

        mineralSum.emplace(sum[i][0], sum[i]);
    }

    int answer = 0;
    while(!mineralSum.empty())
    {
        if(picks[0] > 0)
        {
            picks[0]--;
            answer += mineralSum.top().second[1] + mineralSum.top().second[2] + mineralSum.top().second[3];
        }
        else if(picks[1] > 0)
        {
            picks[1]--;
            answer += mineralSum.top().second[1] * 5 + mineralSum.top().second[2] + mineralSum.top().second[3];
        }
        else if(picks[2] > 0)
        {
            picks[2]--;
            answer += mineralSum.top().second[1] * 25 + mineralSum.top().second[2] * 5 + mineralSum.top().second[3];
        }
        else
            break;
        mineralSum.pop();
    }

    return answer;
}
