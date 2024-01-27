// https://school.programmers.co.kr/learn/courses/30/lessons/169199

// Question
/*
문제 설명
리코쳇 로봇이라는 보드게임이 있습니다.

이 보드게임은 격자모양 게임판 위에서 말을 움직이는 게임으로, 시작 위치에서 목표 위치까지 최소 몇 번만에 도달할 수 있는지 말하는 게임입니다.

이 게임에서 말의 움직임은 상, 하, 좌, 우 4방향 중 하나를 선택해서 게임판 위의 장애물이나 맨 끝에 부딪힐 때까지 미끄러져 이동하는 것을 한 번의 이동으로 칩니다.

다음은 보드게임판을 나타낸 예시입니다.

...D..R
.D.G...
....D.D
D....D.
..D....
여기서 "."은 빈 공간을, "R"은 로봇의 처음 위치를, "D"는 장애물의 위치를, "G"는 목표지점을 나타냅니다.
위 예시에서는 "R" 위치에서 아래, 왼쪽, 위, 왼쪽, 아래, 오른쪽, 위 순서로 움직이면 7번 만에 "G" 위치에 멈춰 설 수 있으며, 이것이 최소 움직임 중 하나입니다.

게임판의 상태를 나타내는 문자열 배열 board가 주어졌을 때, 말이 목표위치에 도달하는데 최소 몇 번 이동해야 하는지 return 하는 solution함수를 완성하세요. 만약 목표위치에 도달할 수 없다면 -1을 return 해주세요.

제한 사항
3 ≤ board의 길이 ≤ 100
3 ≤ board의 원소의 길이 ≤ 100
board의 원소의 길이는 모두 동일합니다.
문자열은 ".", "D", "R", "G"로만 구성되어 있으며 각각 빈 공간, 장애물, 로봇의 처음 위치, 목표 지점을 나타냅니다.
"R"과 "G"는 한 번씩 등장합니다.
입출력 예
board	result
["...D..R", ".D.G...", "....D.D", "D....D.", "..D...."]	7
[".D.R", "....", ".G..", "...D"]	-1
입출력 예 설명
입출력 예 #1

문제 설명의 예시와 같습니다.
입출력 예 #2

.D.R
....
.G..
...D
"R" 위치에 있는 말을 어떻게 움직여도 "G" 에 도달시킬 수 없습니다.
따라서 -1을 return 합니다.
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