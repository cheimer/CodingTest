// Link : https://school.programmers.co.kr/learn/courses/30/lessons/388354

/*
 *  nodes : 노드들의 번호들
 *  edges : 간선 정보
 *  answer : 홀짝 트리, 역활짝 트리 갯수
 *  1 <= nodes.length <= 400000
 *  1 <= edges.length <= 1 000 000
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void FindContainEdges(const vector<vector<int>>& edges, const int startNum, set<int>& outArray)
{
    if (outArray.count(startNum)) return;
    
    outArray.emplace(startNum);
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i][0] == startNum)
        {
            FindContainEdges(edges, edges[i][1], outArray);
        }
        else if (edges[i][1] == startNum)
        {
            FindContainEdges(edges, edges[i][0], outArray);
        }
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {

    vector<set<int>> divNodes;
    set<int> checkNums;
    map<int, vector<int>> edgesMap;

    for (auto& edge : edges)
    {
        edgesMap[edge[0]].push_back(edge[1]);
        edgesMap[edge[1]].push_back(edge[0]);
    }
    
    for (int node : nodes)
    {
        if (checkNums.count(node)) continue;

        divNodes.emplace_back();
        
        FindContainEdges(edges, node, divNodes.back());
        for (int check : divNodes.back())
        {
            checkNums.emplace(check);
        }
    }

    vector<int> answer(2, 0);
    
    for (auto divNode : divNodes)
    {
        int regularNum = 0;
        int reverseNum = 0;
        
        for (auto node : divNode)
        {
            if (edgesMap.count(node) > 0)
            {
                if (((edgesMap[node].size() - 1) % 2 == 0 && node % 2 == 0) || ((edgesMap[node].size() - 1) % 2 == 1 && node % 2 == 1))
                {
                    regularNum++;
                }
                else if (((edgesMap[node].size() - 1) % 2 == 1 && node % 2 == 0) || ((edgesMap[node].size() - 1) % 2 == 0 &&  node % 2 == 1))
                {
                    reverseNum++;
                }
            }
            else
            {
                if (node % 2 == 0)
                {
                    reverseNum++;
                }
                else
                {
                    regularNum++;
                }
            }
        }

        if (reverseNum == 1)
        {
            answer[0]++;
        }
        else if (regularNum == 1)
        {
            answer[1]++;
        }
        
    }

    
    return answer;
}