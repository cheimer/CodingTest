// https://school.programmers.co.kr/learn/courses/30/lessons/172928

// Question
/*
���� ����
�����ٴϴ� ���� 'O', ��ֹ��� 'X'�� ��Ÿ�� ���簢�� ���� ����� �������� �κ� �������� ��å�� �Ϸ��մϴ�. ��å�� �κ� �������� �̸� �Էµ� ��ɿ� ���� �����ϸ�, ����� ������ ���� �������� �־����ϴ�.

["���� �Ÿ�", "���� �Ÿ�" �� ]
���� ��� "E 5"�� �κ� �������� ���� ��ġ���� �������� 5ĭ �̵��ߴٴ� �ǹ��Դϴ�. �κ� �������� ����� �����ϱ� ���� ���� �� ������ ���� Ȯ���մϴ�.

�־��� �������� �̵��� �� ������ ������� Ȯ���մϴ�.
�־��� �������� �̵� �� ��ֹ��� �������� Ȯ���մϴ�.
�� �� ������ ��� �ϳ��� �ش�ȴٸ�, �κ� �������� �ش� ����� �����ϰ� ���� ����� �����մϴ�.
������ ���� ���̰� W, ���� ���̰� H��� �� ��, ������ ���� ����� ��ǥ�� (0, 0), ���� �ϴ��� ��ǥ�� (H - 1, W - 1) �Դϴ�.

������ ��Ÿ���� ���ڿ� �迭 park, �κ� �������� ������ ����� ��� ���ڿ� �迭 routes�� �Ű������� �־��� ��, �κ� �������� ��� ����� ���� �� ���� ��ġ�� [���� ���� ��ǥ, ���� ���� ��ǥ] ������ �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
3 �� park�� ���� �� 50
3 �� park[i]�� ���� �� 50
park[i]�� ���� ���ڵ�� �̷���� ������ ���������� �ϳ��� �־����ϴ�.
S : ���� ����
O : �̵� ������ ���
X : ��ֹ�
park�� ���簢�� ����Դϴ�.
1 �� routes�� ���� �� 50
routes�� �� ���Ҵ� �κ� �������� ������ ��ɾ ��Ÿ���ϴ�.
�κ� �������� routes�� ù ��° ���Һ��� ������� ����� �����մϴ�.
routes�� ���Ҵ� "op n"�� ���� ������ �̷���� ������, op�� �̵��� ����, n�� �̵��� ĭ�� ���� �ǹ��մϴ�.
op�� ���� �� ������ �ϳ��� �̷���� �ֽ��ϴ�.
N : �������� �־��� ĭ��ŭ �̵��մϴ�.
S : �������� �־��� ĭ��ŭ �̵��մϴ�.
W : �������� �־��� ĭ��ŭ �̵��մϴ�.
E : �������� �־��� ĭ��ŭ �̵��մϴ�.
1 �� n �� 9
����� ��
park	routes	result
["SOO","OOO","OOO"]	["E 2","S 2","W 1"]	[2,1]
["SOO","OXX","OOO"]	["E 2","S 2","W 1"]	[0,1]
["OSO","OOO","OXO","OOO"]	["E 2","S 3","W 1"]	[0,0]
����� �� ����
����� �� #1

�Էµ� ��ɴ�� �������� 2ĭ, �������� 2ĭ, �������� 1ĭ �̵��ϸ� [0,0] -> [0,2] -> [2,2] -> [2,1]�� �˴ϴ�.

����� �� #2

�Էµ� ��ɴ�ζ�� �������� 2ĭ, �������� 2ĭ, �������� 1ĭ �̵��ؾ������� �������� 2ĭ �̵��� �� ��ֹ��� �ִ� ĭ�� ������ ������ �ش� ����� ������ ��ɵ鸸 �����ϴ�. ��������δ� [0,0] -> [0,2] -> [0,1]�� �˴ϴ�.

����� �� #3

ó�� �Էµ� ����� ������ ������ �ǰ� �� ��°�� �Էµ� ��� ���� ��ֹ��� �������� �ǹǷ� �� �Է��� ������ �� ��° ��ɸ� �����Ƿ� ����� ������ �����ϴ�. [0,1] -> [0,0]
*/

#include <string>
#include <vector>

#define PARK_MOVABLE 123
#define PARK_IMMOVABLE 456
#define PARK_DENIED 789
#define PARK_SIZE 51

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {

    int parkArr[PARK_SIZE][PARK_SIZE];
    fill_n(&parkArr[0][0], PARK_SIZE * PARK_SIZE, PARK_DENIED);
    pair<int, int> start;

    int row = 0;
    for(string parkString : park)
    {
        for(int column = 0; column < parkString.length(); column++)
        {
            switch(parkString[column])
            {
            case 'S':
                start.first = row;
                start.second = column;
                parkArr[row][column] = PARK_MOVABLE;
                break;
            case 'O':
                parkArr[row][column] = PARK_MOVABLE;
                break;
            case 'X':
                parkArr[row][column] = PARK_IMMOVABLE;
                break;
            default:
                break;
            }
        }
        row++;
    }

    for(string route : routes)
    {
        int distance = route[2] - '0';

        bool moveSN = false, moveEW = false;
        switch(route[0])
        {
        case 'S':
            moveSN = true;
            break;
        case 'N':
            moveSN = true;
            distance *= -1;
            break;
        case 'E':
            moveEW = true;
            break;
        case 'W':
            moveEW = true;
            distance *= -1;
            break;
        default:
            break;
        }

        bool isMove = true;
        if(moveSN)
        {
            if(start.first + distance > PARK_SIZE || start.first + distance < 0)
                continue;

            for(int move = 1; move <= abs(distance); move++)
            {
                int adjustMove = move;
                if(distance < 0)
                    adjustMove *= -1;

                if(parkArr[start.first + adjustMove][start.second] != PARK_MOVABLE)
                {
                    isMove = false;
                    break;
                }
            }
            if(isMove)
                start.first += distance;
        }

        if(moveEW)
        {
            if(start.second + distance > PARK_SIZE || start.second + distance < 0)
                continue;

            for(int move = 1; move <= abs(distance); move++)
            {
                int adjustMove = move;
                if(distance < 0)
                    adjustMove *= -1;

                if(parkArr[start.first][start.second + adjustMove] != PARK_MOVABLE)
                {
                    isMove = false;
                    break;
                }
            }
            if(isMove)
                start.second += distance;
        }

    }

    vector<int> answer;
    answer.push_back(start.first); answer.push_back(start.second);
    return answer;
}