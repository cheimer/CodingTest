/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42583
 *
 * Solution : 정해진 순서로 다리를 건너는 트럭이 건너는 시간 구하기
 *
 *  bridge_length : 다리 길이. 1초에 1씩 건너감
 *  weight : 견딜 수 있는 무게 최대값
 *  truck_weights : 트럭 무게 배열
 *
 *  1 <= bridge_length <= 10000
 *  1 <= weight <= 10000
 *  1 <= truck_weight <= 10000
 */

#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int CurrentWeight = 0;
    queue<int> TruckOnBridge;

    for (int i = 0; i < bridge_length; i++)
    {
        TruckOnBridge.push(0);
    }

    int time = 0;
    int TruckIndex = 0;
    while (time < 10000 * 10001)
    {
        if (TruckIndex >= truck_weights.size())
        {
            time += bridge_length;
            break;
        }
        
        time++;
        
        CurrentWeight -= TruckOnBridge.front();
        TruckOnBridge.pop();

        if (CurrentWeight + truck_weights[TruckIndex] <= weight)
        {
            CurrentWeight += truck_weights[TruckIndex];
            TruckOnBridge.push(truck_weights[TruckIndex]);
            TruckIndex++;
        }
        else
        {
            TruckOnBridge.push(0);
        }
    }
    
    return time;
}
