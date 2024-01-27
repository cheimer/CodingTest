// https://school.programmers.co.kr/learn/courses/30/lessons/169199

// Question
/*
���� ����
������ �κ��̶�� ��������� �ֽ��ϴ�.

�� ��������� ���ڸ�� ������ ������ ���� �����̴� ��������, ���� ��ġ���� ��ǥ ��ġ���� �ּ� �� ������ ������ �� �ִ��� ���ϴ� �����Դϴ�.

�� ���ӿ��� ���� �������� ��, ��, ��, �� 4���� �� �ϳ��� �����ؼ� ������ ���� ��ֹ��̳� �� ���� �ε��� ������ �̲����� �̵��ϴ� ���� �� ���� �̵����� Ĩ�ϴ�.

������ ����������� ��Ÿ�� �����Դϴ�.

...D..R
.D.G...
....D.D
D....D.
..D....
���⼭ "."�� �� ������, "R"�� �κ��� ó�� ��ġ��, "D"�� ��ֹ��� ��ġ��, "G"�� ��ǥ������ ��Ÿ���ϴ�.
�� ���ÿ����� "R" ��ġ���� �Ʒ�, ����, ��, ����, �Ʒ�, ������, �� ������ �����̸� 7�� ���� "G" ��ġ�� ���� �� �� ������, �̰��� �ּ� ������ �� �ϳ��Դϴ�.

�������� ���¸� ��Ÿ���� ���ڿ� �迭 board�� �־����� ��, ���� ��ǥ��ġ�� �����ϴµ� �ּ� �� �� �̵��ؾ� �ϴ��� return �ϴ� solution�Լ��� �ϼ��ϼ���. ���� ��ǥ��ġ�� ������ �� ���ٸ� -1�� return ���ּ���.

���� ����
3 �� board�� ���� �� 100
3 �� board�� ������ ���� �� 100
board�� ������ ���̴� ��� �����մϴ�.
���ڿ��� ".", "D", "R", "G"�θ� �����Ǿ� ������ ���� �� ����, ��ֹ�, �κ��� ó�� ��ġ, ��ǥ ������ ��Ÿ���ϴ�.
"R"�� "G"�� �� ���� �����մϴ�.
����� ��
board	result
["...D..R", ".D.G...", "....D.D", "D....D.", "..D...."]	7
[".D.R", "....", ".G..", "...D"]	-1
����� �� ����
����� �� #1

���� ������ ���ÿ� �����ϴ�.
����� �� #2

.D.R
....
.G..
...D
"R" ��ġ�� �ִ� ���� ��� �������� "G" �� ���޽�ų �� �����ϴ�.
���� -1�� return �մϴ�.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[100][100];
char arr[100][100];
pair<int, int> fourDirections[4];

int solution(vector<string> board) {
    fill_n(&visited[0][0], 100*100, -1);
    fill_n(&arr[0][0], 100*100, ' ');

    fourDirections[0] = make_pair<int, int>(-1, 0);
    fourDirections[1] = make_pair<int, int>(1, 0);
    fourDirections[2] = make_pair<int, int>(0, -1);
    fourDirections[3] = make_pair<int, int>(0, 1);

    int maxRow = board.size();
    int maxColumn = board[0].size();
    int startX, startY, goalX, goalY;

    for(int i = 0; i < maxRow; i++)
    {
        for(int j = 0; j < maxColumn; j++)
        {
            if(board[i][j] == 'R')
            {
                startX = i; startY = j;
            }
            if(board[i][j] == 'G')
            {
                goalX = i; goalY = j;
                arr[i][j] = '.';
            }

            if(board[i][j] == 'D')
                arr[i][j] = 'D';
            else
                arr[i][j] = '.';
        }
    }

    queue<pair<int, int>> que;
    que.emplace(startX, startY);
    visited[startX][startY] = 0;
    int answer = -1;

    while(!que.empty())
    {
        pair<int, int> current = que.front();
        que.pop();

        if(goalX == current.first && goalY == current.second)
        {
            answer = visited[current.first][current.second];
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            pair<int, int> dirIndex;
            dirIndex.first = fourDirections[i].first + current.first;
            dirIndex.second = fourDirections[i].second + current.second;

            if(dirIndex.first < 0 || dirIndex.first >= maxRow || dirIndex.second < 0 || dirIndex.second >= maxColumn)
                continue;
            if(arr[dirIndex.first][dirIndex.second] == 'D')
                continue;

            while(true)
            {
                dirIndex.first += fourDirections[i].first; dirIndex.second += fourDirections[i].second;
                if(dirIndex.first < 0 || dirIndex.first >= maxRow || dirIndex.second < 0 || dirIndex.second >= maxColumn
                    || arr[dirIndex.first][dirIndex.second] == 'D')
                {
                    dirIndex.first -= fourDirections[i].first; dirIndex.second -= fourDirections[i].second;
                    if(visited[dirIndex.first][dirIndex.second] == -1)
                    {
                        que.emplace(dirIndex.first, dirIndex.second);
                        visited[dirIndex.first][dirIndex.second] = visited[current.first][current.second] + 1;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }

        }
    }

    return answer;
}