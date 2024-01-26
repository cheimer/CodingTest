// https://school.programmers.co.kr/learn/courses/30/lessons/159993

// Question
/*
���� ����
1 x 1 ũ���� ĭ��� �̷���� ���簢�� ���� ������ �̷ο��� Ż���Ϸ��� �մϴ�. �� ĭ�� ��� �Ǵ� ������ �����Ǿ� ������, ������ �� ĭ�� ������ �� ���� ��η� �� ĭ���θ� �̵��� �� �ֽ��ϴ�. ��ε� �� �� ĭ���� �̷θ� ���������� ���� �ִµ�, �� ���� ������ ��ܼ��� �� �� �ֽ��ϴ�. ���� ���� ��ε� �� �� ĭ�� �ֽ��ϴ�. ����, ��� �������� ���� ������ �ִ� ĭ���� �̵��Ͽ� ������ ��� �� �̷θ� ���������� ���� �ִ� ĭ���� �̵��ϸ� �˴ϴ�. �̶� ���� ������ ����� �ʾҴ��� �ⱸ�� �ִ� ĭ�� ������ �� �ֽ��ϴ�. �̷ο��� �� ĭ�� �̵��ϴµ� 1�ʰ� �ɸ��ٰ� �� ��, �ִ��� ������ �̷θ� ���������µ� �ɸ��� �ð��� ���Ϸ� �մϴ�.

�̷θ� ��Ÿ�� ���ڿ� �迭 maps�� �Ű������� �־��� ��, �̷θ� Ż���ϴµ� �ʿ��� �ּ� �ð��� return �ϴ� solution �Լ��� �ϼ����ּ���. ����, Ż���� �� ���ٸ� -1�� return ���ּ���.

���ѻ���
5 �� maps�� ���� �� 100
5 �� maps[i]�� ���� �� 100
maps[i]�� ���� 5���� ���ڵ�θ� �̷���� �ֽ��ϴ�.
S : ���� ����
E : �ⱸ
L : ����
O : ���
X : ��
���� ������ �ⱸ, ������ �׻� �ٸ� ���� �����ϸ� �� ������ �����մϴ�.
�ⱸ�� ������ ������� �ʾƵ� ������ �� ������, ��� ���, �ⱸ, ����, �������� ���� �� ������ �� �ֽ��ϴ�.
����� ��
maps	result
["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]	16
["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"]	-1
����� �� ����
����� �� #1

�־��� ���ڿ��� ������ ���� �̷��̸�

image1

4�� �̵��Ͽ� ������ ���� �ⱸ���� �̵��ϸ� �� 16���� �ð��� �ɸ��ϴ�. ���� 16�� ��ȯ�մϴ�.

����� �� #2

���� �������� �̵��� �� �ִ� ������ ��� Ż���� �� �����ϴ�. ���� -1�� ��ȯ�մϴ�.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

char arr[100][100];

int MoveAtoB(pair<int, int> start, pair<int, int> end, int maxRow, int maxColumn);

int solution(vector<string> maps) {

    const int maxRow = maps.size();
    const int maxColumn = maps[0].length();
    pair<int, int> startPos;
    pair<int, int> lockPos;
    pair<int, int> endPos;

    int row = 0;
    for(string map : maps)
    {
        for(int column = 0; column < map.size(); column++)
        {
            char mapChar = map[column];
            arr[row][column] = mapChar;

            if(mapChar == 'S')
            {
                startPos.first = row; startPos.second = column;
            }
            else if(mapChar == 'E')
            {
                endPos.first = row; endPos.second = column;
            }
            else if(mapChar == 'L')
            {
                lockPos.first = row; lockPos.second = column;
            }
        }
        row++;
    }

    int StartToLock = MoveAtoB(startPos, lockPos, maxRow, maxColumn);
    if(StartToLock < 0)
        return -1;

    int LockToEnd = MoveAtoB(lockPos, endPos, maxRow, maxColumn);
    if(LockToEnd < 0)
        return -1;

    int answer = StartToLock + LockToEnd;
    return answer;
}

int MoveAtoB(pair<int, int> start, pair<int, int> end, int maxRow, int maxColumn)
{
    int visited[100][100];
    fill_n(&visited[0][0], 100 * 100, 0);

    queue<pair<int, int>> que;

    visited[start.first][start.second];
    que.emplace(start.first, start.second);

    while(!que.empty())
    {
        pair<int, int> front = que.front();
        que.pop();
        if(front.first - 1 >= 0 && visited[front.first - 1][front.second] == 0 && arr[front.first - 1][front.second] != 'X')
        {
            visited[front.first - 1][front.second] = visited[front.first][front.second] + 1;
            que.emplace(front.first - 1, front.second);
        }
        if(front.first + 1 < maxRow && visited[front.first + 1][front.second] == 0 && arr[front.first + 1][front.second] != 'X')
        {
            visited[front.first + 1][front.second] = visited[front.first][front.second] + 1;
            que.emplace(front.first + 1, front.second);
        }
        if(front.second - 1 >= 0 && visited[front.first][front.second - 1] == 0 && arr[front.first][front.second - 1] != 'X')
        {
            visited[front.first][front.second - 1] = visited[front.first][front.second] + 1;
            que.emplace(front.first, front.second - 1);
        }
        if(front.second + 1 < maxColumn && visited[front.first][front.second + 1] == 0 && arr[front.first][front.second + 1] != 'X')
        {
            visited[front.first][front.second + 1] = visited[front.first][front.second] + 1;
            que.emplace(front.first, front.second + 1);
        }

        if(visited[end.first][end.second] != 0)
        {
            return visited[end.first][end.second];
        }
    }

    return -1;
}