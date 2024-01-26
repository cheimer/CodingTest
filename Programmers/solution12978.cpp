// https://school.programmers.co.kr/learn/courses/30/lessons/12978

// Question
/*
���� ����
N���� ������ �̷���� ���� �ֽ��ϴ�. �� ������ �� �������� 1���� N������ ��ȣ�� ���� �ϳ��� �ο��Ǿ� �ֽ��ϴ�. �� ������ ��������� ������ �� �ִ� ���η� ����Ǿ� �ִµ�, ���� �ٸ� ���� ���� �̵��� ���� �� ���θ� ������ �մϴ�. ���θ� ���� �� �ɸ��� �ð��� ���κ��� �ٸ��ϴ�. ���� 1�� ������ �ִ� ���������� �� ������ ���� ����� �Ϸ��� �մϴ�. �� �����κ��� ���� �ֹ��� �������� �ϴµ�, N���� ���� �߿��� K �ð� ���Ϸ� ����� ������ ���������� �ֹ��� �������� �մϴ�. ������ N = 5, K = 3�� ����� �����Դϴ�.

�� �׸����� 1�� ������ �ִ� �������� [1, 2, 4, 5] �� ���������� 3 ������ �ð��� ����� �� �ֽ��ϴ�. �׷��� 3�� ���������� 3�ð� �̳��� ����� �� �ִ� ��ΰ� �����Ƿ� 3�� ���������� �ֹ��� ���� �ʽ��ϴ�. ���� 1�� ������ �ִ� �������� ��� �ֹ��� ���� �� �ִ� ������ 4���� �˴ϴ�.
������ ���� N, �� ������ �����ϴ� ������ ���� road, ���� ����� ������ �ð� K�� �Ű������� �־��� ��, ���� �ֹ��� ���� �� �ִ� ������ ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
������ ���� N�� 1 �̻� 50 ������ �ڿ����Դϴ�.
road�� ����(���� ������ ����)�� 1 �̻� 2,000 �����Դϴ�.
road�� �� ���Ҵ� ������ �����ϰ� �ִ� �� ������ ������ ��Ÿ���ϴ�.
road�� ���̰� 3�� �迭�̸�, ������� (a, b, c)�� ��Ÿ���ϴ�.
a, b(1 �� a, b �� N, a != b)�� ���ΰ� �����ϴ� �� ������ ��ȣ�̸�, c(1 �� c �� 10,000, c�� �ڿ���)�� ���θ� �����µ� �ɸ��� �ð��Դϴ�.
�� ���� a, b�� �����ϴ� ���δ� ���� ���� ���� �� �ֽ��ϴ�.
�� ������ ������ ���� �� �ߺ��ؼ� �־����� �ʽ��ϴ�.
K�� ���� ����� ������ �ð��� ��Ÿ����, 1 �̻� 500,000 �����Դϴ�.
������ �� �������� �׻� �̵� ������ ��ΰ� �����մϴ�.
1�� ������ �ִ� �������� K ������ �ð��� ����� ������ ������ ������ return �ϸ� �˴ϴ�.
����� ��
N	road	K	result
5	[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]	3	4
6	[[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]]	4	4
����� �� ����
����� �� #1
������ ���ÿ� �����ϴ�.

����� �� #2
�־��� ������ ������ ����� �Ʒ� �׸��� �����ϴ�.
1�� �������� ��޿� 4�ð� ���ϰ� �ɸ��� ������ [1, 2, 3, 5] 4���̹Ƿ� 4�� return �մϴ�.
*/


#include <vector>
#include <queue>
#include <stdint.h>

using namespace std;


int visitedArr[51];

int solution(int N, vector<vector<int>> roads, int maxLen) {

    for(int i = 0; i < 51; i++)
    {
        visitedArr[i] = INT32_MAX;
    }
    visitedArr[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue;
    queue<int> visitQueue;
    visitQueue.push(1);

    while(!visitQueue.empty())
    {
        int currentPoint = visitQueue.front();
        visitQueue.pop();

        for(vector<int> road: roads)
        {
            int currentLen = visitedArr[currentPoint];
            if(currentLen + road[2] > maxLen)
                continue;

            if(road[0] == currentPoint && visitedArr[road[1]] > currentLen + road[2])
            {
                visitedArr[road[1]] = currentLen + road[2];
                visitQueue.push(road[1]);
            }
            else if(road[1] == currentPoint && visitedArr[road[0]] > currentLen + road[2])
            {
                visitedArr[road[0]] = currentLen + road[2];
                visitQueue.push(road[0]);
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < 51; i++)
    {
        if(visitedArr[i] != INTMAX_MAX)
        {
            answer++;
        }
    }
    return answer;
}
