// https://school.programmers.co.kr/learn/courses/30/lessons/77485

// Question
/*
������ 6 x 6 ũ�� ����� �����Դϴ�.

grid_example.png

�� ��Ŀ� (2, 2, 5, 4) ȸ���� �����ϸ�, �Ʒ� �׸��� ���� 2�� 2������ 5�� 4������ ������ �׵θ��� �ð�������� ȸ���մϴ�. �̶�, �߾��� 15�� 21�� �ִ� ������ ȸ������ �ʴ� ���� �����ϼ���.

rotation_example.png

����� ���� ����(�� ����) rows, ���� ����(�� ����) columns, �׸��� ȸ������ ��� queries�� �־��� ��, �� ȸ������ �迭�� ������ ��, �� ȸ���� ���� ��ġ�� �ٲ� ���ڵ� �� ���� ���� ���ڵ��� ������� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
rows�� 2 �̻� 100 ������ �ڿ����Դϴ�.
columns�� 2 �̻� 100 ������ �ڿ����Դϴ�.
ó���� ��Ŀ��� ���� �������� ���ڰ� 1���� �ϳ��� �����ϸ鼭 �����ֽ��ϴ�.
��, �ƹ� ȸ���� ���� �ʾ��� ��, i �� j ���� �ִ� ���ڴ� ((i-1) x columns + j)�Դϴ�.
queries�� ���� ����(ȸ���� ����)�� 1 �̻� 10,000 �����Դϴ�.
queries�� �� ���� 4���� ���� [x1, y1, x2, y2]�Դϴ�.
x1 �� y1 ������ x2 �� y2 ������ ������ �׵θ��� �ð�������� ȸ���Ѵٴ� ���Դϴ�.
1 �� x1 < x2 �� rows, 1 �� y1 < y2 �� columns�Դϴ�.
��� ȸ���� ������� �̷�����ϴ�.
���� ���, �� ��° ȸ���� ���� ���� ù ��° ȸ���� ������ ����, �� ���¿��� �� ��° ȸ���� �������� �� �̵��� ���� �� �ּڰ��� ���ϸ� �˴ϴ�.
����� ����
rows	columns	queries	result
6	6	[[2,2,5,4],[3,3,6,6],[5,1,6,3]]	[8, 10, 25]
3	3	[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]	[1, 1, 5, 3]
100	97	[[1,1,100,97]]	[1]
����� �� ����
����� �� #1

ȸ���� �����ϴ� ������ �׸����� ǥ���ϸ� ������ �����ϴ�.
example1.png
����� �� #2

ȸ���� �����ϴ� ������ �׸����� ǥ���ϸ� ������ �����ϴ�.
example2.png
����� �� #3

�� ���ÿ����� ����� �׵θ��� ��ġ�� ��� ĭ���� �����Դϴ�. ����, ����� �׵θ��� �ִ� �� �� ���� ���� ������ 1�� �ٷ� ���� �˴ϴ�.
*/

#include <vector>

using namespace std;
int arr[101][101];

int ChangeArr(int x, int y, int num)
{
    int storeNum = arr[x][y];
    arr[x][y] = num;
    return storeNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {

    for(int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            arr[row][column] = (row * columns) + column + 1;
        }
    }

    vector<int> answer;

    for(vector<int> query : queries)
    {
        int x1 = query[0] - 1, y1 = query[1] - 1, x2 = query[2] - 1, y2 = query[3] - 1;
        int beforeNum = arr[x1][y1], min = beforeNum;

        for(int index = y1 + 1; index <= y2; index++)
        {
            beforeNum = ChangeArr(x1, index, beforeNum);
            if(min > beforeNum)
                min = beforeNum;
        }
        for(int index = x1 + 1; index <= x2; index++)
        {
            beforeNum = ChangeArr(index, y2, beforeNum);
            if(min > beforeNum)
                min = beforeNum;
        }
        for(int index = y2 - 1; index >= y1; index--)
        {
            beforeNum = ChangeArr(x2, index, beforeNum);
            if(min > beforeNum)
                min = beforeNum;
        }
        for(int index = x2 - 1; index >= x1; index--)
        {
            beforeNum = ChangeArr(index, y1, beforeNum);
            if(min > beforeNum)
                min = beforeNum;
        }
        answer.push_back(min);
    }

    return answer;
}