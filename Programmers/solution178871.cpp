// https://school.programmers.co.kr/learn/courses/30/lessons/178871

// Question
/*
���� ����
�ῡ���� �ų� �޸��� ���ְ� �����ϴ�. �ؼ������� �������� �ڱ� �ٷ� ���� ������ �߿��� �� �߿��� ������ �̸��� �θ��ϴ�. ���� ��� 1����� 3����� "mumu", "soe", "poe" �������� ������� �޸��� ���� ��, �ؼ����� "soe"������ �ҷ��ٸ� 2���� "soe" ������ 1���� "mumu" ������ �߿��ߴٴ� ���Դϴ�. �� "soe" ������ 1��, "mumu" ������ 2������ �ٲ�ϴ�.

�������� �̸��� 1����� ���� ��� ������� ��� ���ڿ� �迭 players�� �ؼ����� �θ� �̸��� ���� ���ڿ� �迭 callings�� �Ű������� �־��� ��, ���ְ� ������ �� �������� �̸��� 1����� ��� ������� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���.

���ѻ���
5 �� players�� ���� �� 50,000
players[i]�� i��° ������ �̸��� �ǹ��մϴ�.
players�� ���ҵ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
players���� �ߺ��� ���� �� ���� �ʽ��ϴ�.
3 �� players[i]�� ���� �� 10
2 �� callings�� ���� �� 1,000,000
callings�� players�� ���ҵ�θ� �̷���� �ֽ��ϴ�.
���� ������ 1���� ������ �̸��� �Ҹ��� �ʽ��ϴ�.
����� ��
players	callings	result
["mumu", "soe", "poe", "kai", "mine"]	["kai", "kai", "mine", "mine"]	["mumu", "kai", "mine", "soe", "poe"]
����� �� ����
����� �� #1

4���� "kai" ������ 2�� �߿��Ͽ� 2���� �ǰ� �ռ� 3��, 2���� "poe", "soe" ������ 4��, 3���� �˴ϴ�. 5���� "mine" ������ 2�� �߿��Ͽ� 4��, 3���� "poe", "soe" ������ 5��, 4���� �ǰ� ���ְ� �����ϴ�. 1����� �迭�� ������ ["mumu", "kai", "mine", "soe", "poe"]�� �˴ϴ�.
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

string playerRank[50001];

vector<string> solution(vector<string> players, vector<string> callings) {

	map<string, int> PlayerMap;

	int rank = 0;
	for (string player : players)
	{
		PlayerMap[player] = rank;
		playerRank[rank] = player;
		rank++;
	}

	for (string calling : callings)
	{
		map<string, int>::iterator iter = PlayerMap.find(calling);

		string frontPlayer = playerRank[iter->second - 1];
		playerRank[iter->second - 1] = iter->first;
		playerRank[iter->second] = frontPlayer;

		map<string, int>::iterator frontIter = PlayerMap.find(frontPlayer);
		frontIter->second += 1;
		iter->second -= 1;

	}

	vector<string> answer;

	for (int i = 0; i < PlayerMap.size(); i++)
	{
		answer.push_back(playerRank[i]);
	}

	return answer;
}
