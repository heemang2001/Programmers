#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> vec1, vector<int> vec2)
{
	return vec1.size() < vec2.size();
}

vector<int> MakeNum(string sTemp)
{
	vector<int> vec;

	string sNum = "";

	for (int i = 0; i < sTemp.size(); i++)
	{
		if (sTemp[i] != ',')
		{
			sNum += sTemp[i];
		}

		else if (sTemp[i] == ',')
		{
			vec.push_back(stoi(sNum));
			sNum = ""; 
			continue;
		}

		if(i == sTemp.size() - 1)
		{
			vec.push_back(stoi(sNum));
			sNum = "";			
		}
	}

	return vec;
}

vector<int> solution(string s)
{
	vector<int> answer;
	vector<vector<int>> vecNum;

	bool bOpen = false;
	string sTemp = "";

	for (int i = 1; i < s.size() - 1; i++)
	{
		if (bOpen && s[i] != '}')
		{
			sTemp += s[i];
		}

		else if (s[i] == '{')
		{
			bOpen = true;
		}

		else if(s[i] == '}' && bOpen)
		{
			bOpen = false;		
			vector<int> vecTemp = MakeNum(sTemp);
			vecNum.push_back(vecTemp);
			sTemp = "";
		}
	}

	sort(vecNum.begin(), vecNum.end(), cmp);
		
	for (int i = 0; i < vecNum.size(); i++)
	{
		if (vecNum[i].size() == 1)
		{
			answer.push_back(vecNum[i][0]);			
		}

		else if(vecNum[i].size() > 1)
		{
			for (int j = 0; j < vecNum[i].size(); j++)
			{
				auto iter = find(answer.begin(), answer.end(), vecNum[i][j]);

				if (iter != answer.end())
				{
					continue;
				}

				else
				{
					answer.push_back(vecNum[i][j]);
				}
			}
		}
	}

	return answer;
}

int main()
{
	//vector<int> vecAnswer = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");	// [2, 1, 3, 4]
	//vector<int> vecAnswer = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");	// [2, 1, 3, 4]
	//vector<int> vecAnswer = solution("{{20,111},{111}}");	// [111, 20]
	vector<int> vecAnswer = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");	// [3, 2, 4, 1]

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}