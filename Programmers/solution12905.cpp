// https://school.programmers.co.kr/learn/courses/30/lessons/12905

// Question
/*
1�� 0�� ä���� ǥ(board)�� �ֽ��ϴ�. ǥ 1ĭ�� 1 x 1 �� ���簢������ �̷���� �ֽ��ϴ�. ǥ���� 1�� �̷���� ���� ū ���簢���� ã�� ���̸� return �ϴ� solution �Լ��� �ϼ��� �ּ���. (��, ���簢���̶� �࿡ ������ ���簢���� ���մϴ�.)

���� ���

1	2	3	4
0	1	1	1
1	1	1	1
1	1	1	1
0	0	1	0
�� �ִٸ� ���� ū ���簢����

1	2	3	4
0	1	1	1
1	1	1	1
1	1	1	1
0	0	1	0
�� �Ǹ� ���̴� 9�� �ǹǷ� 9�� ��ȯ�� �ָ� �˴ϴ�.

���ѻ���
ǥ(board)�� 2���� �迭�� �־����ϴ�.
ǥ(board)�� ��(row)�� ũ�� : 1,000 ������ �ڿ���
ǥ(board)�� ��(column)�� ũ�� : 1,000 ������ �ڿ���
ǥ(board)�� ���� 1�Ǵ� 0���θ� �̷���� �ֽ��ϴ�.
����� ��
board	answer
[[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]	9
[[0,0,1,1],[1,1,1,1]]	4
����� �� ����
����� �� #1
���� ���ÿ� �����ϴ�.

����� �� #2
| 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 |
�� ���� ū ���簢���� ���̴� 4�� �ǹǷ� 4�� return�մϴ�.
*/

#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int arr[1001][1001];
    fill_n(&arr[0][0], 1001 * 1001, 0);

    int answerLen = 0;
    for(int i = 1; i < board.size() + 1; i++)
    {
        for(int j = 1; j < board[0].size() + 1; j++)
        {
            if(board[i - 1][j - 1] == 1)
            {
                arr[i][j] = min(min(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j-1]) + 1;
                if(arr[i][j] > answerLen)
                    answerLen = arr[i][j];
            }
        }
    }


    return answerLen * answerLen;
}

// Ǯ�� ������