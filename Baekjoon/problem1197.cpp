/*
/*
 *  Link : https://www.acmicpc.net/problem/1197
 #1#

#include "iostream"
#include "vector"
#include "queue"

using namespace std;

struct Edge
{
    int aIndex;
    int bIndex;
    int weight;

    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    priority_queue<Edge> edges;
    vector<int> nodes(V + 1, 0);

    for (int i = 0; i < E; i++)
    {
        Edge edge;
        cin >> edge.aIndex >> edge.bIndex >> edge.weight;

        edges.emplace(edge);
    }

    while (!edges.empty())
    {
        cout << edges.top().weight << ' ';
        edges.pop();
    }
    
}
*/
