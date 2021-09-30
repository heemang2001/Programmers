#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

map<string, int> mapMenu;

bool compare(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

void DFS(string& order, string sTemp, int index, int cnt)
{
	// cnt == course[j]의 길이면 조합이 완성이므로 DFS종료 
	if (cnt == sTemp.length())
	{
		mapMenu[sTemp]++;
		return;
	}

	for (int i = index; i < order.size(); i++)
	{
		sTemp[cnt] = order[i];
		DFS(order, sTemp, i + 1, cnt + 1);
	}
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	for (int i = 0; i < orders.size(); i++)
	{
		sort(orders[i].begin(), orders[i].end());

		for (int j = 0; j < course.size(); j++)
		{
			string sTemp = "";
			sTemp.resize(course[j]);
			DFS(orders[i], sTemp, 0, 0);
		}
	}

	vector<pair<string, int>> vecSorted;

	// 정렬위해 map에서 vector로 옮겨줌
	for (auto order : mapMenu)
	{
		if (order.second > 1)
		{
			vecSorted.push_back({order.first, order.second});
		}
	}

	sort(vecSorted.begin(), vecSorted.end(), compare);

	for (int i = 0; i < course.size(); i++)
	{
		int max = 0;

		for (int j = 0; j < vecSorted.size(); j++)
		{
			if (vecSorted[j].first.length() != course[i])
			{
				continue;
			}

			else if(max == 0)
			{
				answer.push_back(vecSorted[j].first);
				max = vecSorted[j].second;
			}

			else if (max == vecSorted[j].second)
			{
				answer.push_back(vecSorted[j].first);
			}

			else
			{
				break;
			}
		}

		sort(answer.begin(), answer.end());
	}

	return answer;
}

int main()
{
	vector<string> vecAnswer = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });

	sort(vecAnswer.begin(), vecAnswer.end());

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}