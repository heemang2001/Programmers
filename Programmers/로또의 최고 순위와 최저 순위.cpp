#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void AddAnswer(vector<int>& answer, int SucessNum)
{
	if (SucessNum == 6)
	{
		answer.push_back(1);
	}

	else if (SucessNum == 5)
	{
		answer.push_back(2);
	}

	else if (SucessNum == 4)
	{
		answer.push_back(3);
	}

	else if (SucessNum == 3)
	{
		answer.push_back(4);
	}

	else if (SucessNum == 2)
	{
		answer.push_back(5);
	}

	else
	{
		answer.push_back(6);
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
		
	int Success1 = 0;
	int Success2 = 0;
	int Zero_Cnt = count(lottos.begin(), lottos.end(), 0);

	for (int i = 0; i < win_nums.size(); i++)
	{
		auto iter = find(lottos.begin(), lottos.end(), win_nums[i]);		

		// 못찾음
		if (iter == lottos.end())
		{
			if (Zero_Cnt > 0)
			{
				Zero_Cnt--;
				Success1++;
			}
		}

		// 찾음
		else
		{			
			Success1++;
			Success2++;
		}
	}

	AddAnswer(answer, Success1);
	AddAnswer(answer, Success2);

	return answer;
}

int main()
{
	//vector<int> vecTemp = solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 }); // 3, 5
	//vector<int> vecTemp = solution({ 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 }); // 1, 6
	vector<int> vecTemp = solution({ 45, 4, 35, 20, 3, 9 }, { 20, 9, 3, 45, 4, 35 }); // 1, 1

	for (int i = 0; i < vecTemp.size(); i++)
	{
		cout << vecTemp[i] << '\n';
	}

	return 0;
}