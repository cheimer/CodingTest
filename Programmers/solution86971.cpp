/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/86971
 *
 * Solution : 트리의 연결 점을 하나 끊어서 두 트리 노드 차이를 최소화한 값
 *
 * n : 노드 갯수
 * wires : 연결된 노드 0 <-> 1
 *
 * 2 <= n <= 100
 * wires.Length = n - 1
 * 1 <= wires[0] < wires[1] <= n
 */

#include <vector>
#include <map>
#include <queue>

using namespace std;

static map<int, vector<int>> LinkedNodes;

int GetLen(int Node, int CutNode)
{
    queue<int> ReserveNodes;
    ReserveNodes.push(Node);
    
    bool visited[111];
    fill_n(visited, 111, false);
    visited[CutNode] = true;

    int Len = 0;
    while (!ReserveNodes.empty())
    {
        int CurrentNode = ReserveNodes.front();
        ReserveNodes.pop();

        if (visited[CurrentNode])
        {
            continue;
        }
        else
        {
            Len++;
            visited[CurrentNode] = true;
            for (auto LinkedNode : LinkedNodes[CurrentNode])
            {
                ReserveNodes.push(LinkedNode);
            }
            
        }
    }

    return Len;
}

int GetLenDifWhenCut(const vector<int>& CutNodes)
{
    int LeftLen = GetLen(CutNodes[0], CutNodes[1]);
    int RightLen = GetLen(CutNodes[1], CutNodes[0]);

    return abs(LeftLen - RightLen);
}

int solution(int n, vector<vector<int>> wires)
{
    for (auto& wire : wires)
    {
        LinkedNodes[wire[0]].push_back(wire[1]);
        LinkedNodes[wire[1]].push_back(wire[0]);
    }

    int answer = 999;
    for (int i = 0; i < wires.size(); i++)
    {
        int LenDif = GetLenDifWhenCut(wires[i]);
        answer = min(answer, LenDif);
    }
    
    return answer;
}
