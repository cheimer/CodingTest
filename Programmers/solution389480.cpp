// Link : https://school.programmers.co.kr/learn/courses/30/lessons/389480

/*
 *   info[i] : i 에 대한 도득 흔적 갯수
 *   n : A 도둑 흔적 한계값
 *   m : B 도득 흔적 한계값
 *   answer : 두 도둑이 안 잡히면서 A 도둑 흔적의 최소값 불가능하면 -1
 *   
 *   1 <= info.length <= 40
 *   
*/

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

const int MAX_VALUE = 1234567890;

map<int, set<pair<int, int>>> visited;

int DFS(const vector<vector<int>>& info, const int index, const pair<int, int> values, const int n, const int m)
{
    if (info.size() == index) return values.first;

    if (visited.count(index) && visited[index].count(values))
    {
        return MAX_VALUE;
    }
    
    visited[index].emplace(values);

    pair<int, int> AValues = values;
    AValues.first += info[index][0];
    pair<int, int> BValues = values;
    BValues.second += info[index][1];

    int minValue = MAX_VALUE;
    if (AValues.first < n)
    {
        int tempValue = DFS(info, index + 1, AValues, n, m);

        if (minValue != -1)
        {
            minValue = std::min(tempValue, minValue);
        }
    }

    if (BValues.second < m)
    {
        int tempValue = DFS(info, index + 1, BValues, n, m);

        if (minValue != -1)
        {
            minValue = std::min(tempValue, minValue);
        }
    }


    return minValue;
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = DFS(info, 0, make_pair(0, 0), n, m);

    if (answer == MAX_VALUE)
    {
        return -1;
    }
    else
    {
        return answer;
    }
}