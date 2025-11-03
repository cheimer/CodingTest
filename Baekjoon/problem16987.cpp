/*
/*
 *  Link : https://www.acmicpc.net/problem/16987
 #1#

#include <algorithm>

#include "iostream"
#include "vector"

using namespace std;

void BT(int currentIndex, const vector< int>& eggsWeight, vector<int>& currentHealth, int& outBroken)
{
    if (currentIndex >= eggsWeight.size())
    {
        int broken = 0;
        for (int currentValue : currentHealth)
        {
            if (currentValue <= 0)
            {
                broken++;
            }
        }
        outBroken = max(outBroken, broken);
        return;
    }

    if (currentHealth[currentIndex] <= 0)
    {
        BT(currentIndex + 1, eggsWeight, currentHealth, outBroken);
        return;
    }
    
    for (size_t i = 0; i < eggsWeight.size(); i++)
    {
        if (i == currentIndex) continue;
        if (currentHealth[i] <= 0) continue;

        currentHealth[currentIndex] -= eggsWeight[i];
        currentHealth[i] -= eggsWeight[currentIndex];
        
        int currentBroken = 0;
        for (int currentValue : currentHealth)
        {
            if (currentValue <= 0)
            {
                currentBroken++;
            }
        }
        
        BT(currentIndex + 1, eggsWeight, currentHealth, currentBroken);
        
        currentHealth[currentIndex] += eggsWeight[i];
        currentHealth[i] += eggsWeight[currentIndex];
        
        outBroken = std::max(outBroken, currentBroken);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> eggsWeight(N, 0);
    vector<int> remainHealth(N, 0);
    
    for (int i = 0; i < N; i++)
    {
        int S, W;
        cin >> S >> W;

        eggsWeight[i] = W;
        remainHealth[i] = S;
    }

    int answer = 0;
    BT(0, eggsWeight, remainHealth, answer);

    cout << answer;
    
}
*/
