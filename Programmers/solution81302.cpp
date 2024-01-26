// https://school.programmers.co.kr/learn/courses/30/lessons/81302

// Question
/*
�����ڸ� ����ϴ� �Ҹ��� īī���� ������ ���� �Խ��ϴ�.

�ڷγ� ���̷��� ���� ������ ���� �����ڵ��� �Ÿ��� �ּ� ��⸦ �ؾ��ϴµ� ���� ���� ������ ��ŭ
�Ʒ��� ���� ��Ģ���� ���ǿ� �Ÿ��� �ΰ� �ɵ��� �ȳ��ϰ� �ֽ��ϴ�.

������ 5���̸�, �� ������ 5x5 ũ���Դϴ�.
�Ÿ��α⸦ ���Ͽ� �����ڵ� ������ ����ư �Ÿ�1�� 2 ���Ϸ� ���� ���� �ּ���.
�� �����ڰ� �ɾ��ִ� �ڸ� ���̰� ��Ƽ������ ���� ���� ��쿡�� ����մϴ�.
���� ���,

�� �׸�ó�� �ڸ� ���̿� ��Ƽ���� �����Ѵٸ� ����ư �Ÿ��� 2���� �Ÿ��α⸦ ��Ų ���Դϴ�.	�� �׸�ó�� ��Ƽ���� ���̿� �ΰ� ���� ��쵵 �Ÿ��α⸦ ��Ų ���Դϴ�.	�� �׸�ó�� �ڸ� ���̰� ����ư �Ÿ� 2�̰� ���̿� �� ���̺��� �ִ� ���� �Ÿ��α⸦ ��Ű�� ���� ���Դϴ�.
�����ڰ� �ɾ��ִ� �ڸ�(P)�� �ǹ��մϴ�.	�� ���̺�(O)�� �ǹ��մϴ�.	��Ƽ��(X)�� �ǹ��մϴ�.
5���� ������ �� �Ҹ���� �� ���ǿ��� �����ڵ��� �Ÿ��α⸦ �� ��Ű�� �ִ��� �˰� �;������ϴ�. �ڸ��� �ɾ��ִ� �����ڵ��� ������ ���� ������ ���Ǻ��� ���� 2���� ���ڿ� �迭 places�� �Ű������� �־����ϴ�. �� ���Ǻ��� �Ÿ��α⸦ ��Ű�� ������ 1��, �� ���̶� ��Ű�� �ʰ� ������ 0�� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
places�� �� ����(���� ����) = 5
places�� �� ���� �ϳ��� ���� ������ ��Ÿ���ϴ�.
places�� �� ����(���� ���� ����) = 5
places�� ���Ҵ� P,O,X�� �̷���� ���ڿ��Դϴ�.
places ������ ����(���� ���� ����) = 5
P�� �����ڰ� �ɾ��ִ� �ڸ��� �ǹ��մϴ�.
O�� �� ���̺��� �ǹ��մϴ�.
X�� ��Ƽ���� �ǹ��մϴ�.
�Է����� �־����� 5�� ������ ũ��� ��� 5x5 �Դϴ�.
return �� ����
1���� ���� �迭�� 5���� ���Ҹ� ��Ƽ� return �մϴ�.
places�� ��� �ִ� 5�� ������ �������, �Ÿ��α� �ؼ� ���θ� ���ʴ�� �迭�� ����ϴ�.
�� ���� ���� ��� �����ڰ� �Ÿ��α⸦ ��Ű�� ������ 1��, �� ���̶� ��Ű�� �ʰ� ������ 0�� ����ϴ�.
����� ��
places	result
[["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]	[1, 0, 1, 1, 1]
����� �� ����
����� �� #1

ù ��° ����

No.	0	1	2	3	4
0	P	O	O	O	P
1	O	X	X	O	X
2	O	P	X	P	X
3	O	O	X	O	X
4	P	O	X	X	P
��� �����ڰ� �Ÿ��α⸦ ��Ű�� �ֽ��ϴ�.
�� ��° ����

No.	0	1	2	3	4
0	P	O	O	P	X
1	O	X	P	X	P
2	P	X	X	X	O
3	O	X	X	X	O
4	O	O	O	P	P
(0, 0) �ڸ��� �����ڿ� (2, 0) �ڸ��� �����ڰ� �Ÿ��α⸦ ��Ű�� ���� �ʽ��ϴ�.
(1, 2) �ڸ��� �����ڿ� (0, 3) �ڸ��� �����ڰ� �Ÿ��α⸦ ��Ű�� ���� �ʽ��ϴ�.
(4, 3) �ڸ��� �����ڿ� (4, 4) �ڸ��� �����ڰ� �Ÿ��α⸦ ��Ű�� ���� �ʽ��ϴ�.
�� ��° ����

No.	0	1	2	3	4
0	P	X	O	P	X
1	O	X	O	X	P
2	O	X	P	O	X
3	O	X	X	O	P
4	P	X	P	O	X
��� �����ڰ� �Ÿ��α⸦ ��Ű�� �ֽ��ϴ�.
�� ��° ����

No.	0	1	2	3	4
0	O	O	O	X	X
1	X	O	O	O	X
2	O	O	O	X	X
3	O	X	O	O	X
4	O	O	O	O	O
���ǿ� �����ڰ� �����Ƿ� �Ÿ��α⸦ ��Ű�� �ֽ��ϴ�.
�ټ� ��° ����

No.	0	1	2	3	4
0	P	X	P	X	P
1	X	P	X	P	X
2	P	X	P	X	P
3	X	P	X	P	X
4	P	X	P	X	P
��� �����ڰ� �Ÿ��α⸦ ��Ű�� �ֽ��ϴ�.
�� ��° ������ ������ ��� ���ǿ��� �Ÿ��αⰡ �������� �����Ƿ�, �迭 [1, 0, 1, 1, 1]�� return �մϴ�.

���ѽð� �ȳ�
��Ȯ�� �׽�Ʈ : 10��

�� ���̺� T1, T2�� ��� (r1, c1), (r2, c2)�� ���� ��ġ�ϰ� �ִٸ�, T1, T2 ������ ����ư �Ÿ��� |r1 - r2| + |c1 - c2| �Դϴ�. ?
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<string>& place, int startX, int startY);

pair<int, int> fourDirections[4];

vector<int> solution(vector<vector<string>> places) {

    fourDirections[0] = make_pair<int, int>(-1, 0);
    fourDirections[1] = make_pair<int, int>(1, 0);
    fourDirections[2] = make_pair<int, int>(0, -1);
    fourDirections[3] = make_pair<int, int>(0, 1);

    vector<int> answer;
    for(vector<string> place : places)
    {
        bool isGood = true;
        for(int row = 0; row < 5; row++)
        {
            for(int column = 0; column < 5; column++)
            {
                if(place[row][column] == 'P')
                {
                    if(!bfs(place, row, column))
                    {
                        isGood = false;
                        row = 999;
                        break;
                    }
                }
            }
        }
        if(isGood)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

bool bfs(vector<string>& place, int startX, int startY)
{
    int visited[5][5];
    fill_n(&visited[0][0], 5 * 5, 0);
    queue<pair<int, int>> que;
    que.emplace(startX, startY);
    visited[startX][startY] = 1;

    while(!que.empty())
    {
        pair<int, int> front = que.front();
        if(visited[front.first][front.second] == 3)
            return true;

        que.pop();

        for(int i = 0; i < 4; i++)
        {
            pair<int, int> dirIndex;
            dirIndex.first = fourDirections[i].first + front.first;
            dirIndex.second = fourDirections[i].second + front.second;

            if(dirIndex.first < 0 || dirIndex.first >= 5 || dirIndex.second < 0 || dirIndex.second >= 5)
                continue;
            if(visited[dirIndex.first][dirIndex.second] != 0)
                continue;

            if(place[dirIndex.first][dirIndex.second] == 'O')
            {
                que.emplace(dirIndex.first, dirIndex.second);
                visited[dirIndex.first][dirIndex.second] = visited[front.first][front.second] + 1;
            }
            else if(place[dirIndex.first][dirIndex.second] == 'P')
                return false;
        }

    }
    return true;
}
