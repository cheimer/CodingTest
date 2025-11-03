/*
/*
 *  Link : https://www.acmicpc.net/problem/
 #1#

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct Node
{
    string name;
    int firstNum;
    int secondNum;
    int thirdNum;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Node> nodeVec;

    for (int i = 0; i < N; i++)
    {
        Node node;
        cin >> node.name >> node.firstNum >> node.secondNum >> node.thirdNum;
        nodeVec.push_back(node);
    }

    sort(nodeVec.begin(), nodeVec.end(),
        [](const Node& A, const Node& B) -> bool
        {
            if (A.firstNum != B.firstNum)
            {
                return A.firstNum > B.firstNum;
            }
            else if (A.secondNum != B.secondNum)
            {
                return A.secondNum < B.secondNum;
            }
            else if (A.thirdNum != B.thirdNum)
            {
                return A.thirdNum > B.thirdNum;
            }
            else
            {
                return A.name < B.name;
            }
        }
    );


    for (const Node& node : nodeVec)
    {
        cout<<node.name<<'\n';
    }
    
}
*/
