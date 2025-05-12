/*
* Link : https://school.programmers.co.kr/learn/courses/30/lessons/42578
 * 
 * Clothes : <의상의 이름, 의상의 종류>의 2차원 배열
 * Answer : 서로 다은 옷의 조합 수
 * 완주못한 선수 이름 String : Answer
 * 
 * 조건 : 1 <= Clothes.Length <= 30
 *  같은 이름의 의상은 X
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> Clothes)
{
    unordered_map<string, int> ClothesNum;
    vector<string> ClothTypes;

    for (auto ClothNameType : Clothes)
    {
        string& ClothType = ClothNameType[1];
        
        if (ClothesNum.count(ClothType) > 0)
        {
            ClothesNum[ClothType]++;
        }
        else
        {
            ClothesNum.insert(make_pair(ClothType, 1));
            ClothTypes.push_back(ClothType);
        }
    }

    int answer = 1;    

    // 경우의 수 : 각 배열마다 1개 선택하거나 선택안하는 경우(ex A, B 일 경우 A B "" 의 3가지)를 각각 곱한 후 모두 선택안하는 경우를 제외함
    for (const auto& ClothType : ClothTypes)
    {
        answer = answer * (ClothesNum[ClothType] + 1);
    }

    answer -= 1;
    
    return answer;    
    
}
