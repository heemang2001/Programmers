#include <string.h>
#include <vector>
#include <iostream>
#include <sstream> // ���ڿ� �Ľ� �Լ�
#include <algorithm>
#include <unordered_map>

using namespace std;

#include <string>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> hashScores;

void addCases(string* s, int score)
{
	for (int i = 0; i < 16; i++)
	{
		string str = "";
		int nTemp = i;

		for (int j = 3; j >= 0; j--)
		{
			if (nTemp <= 0 || nTemp % 2 == 0)
			{
				str = '-' + str;
			}

			else
			{
				str = s[j] + str;
			}

			nTemp /= 2;
		}

		hashScores[str].push_back(score);
	}
}

vector<int> solution(vector<string> info, vector<string> query)
{
	vector<int> answer;
	string s[4];
	string sTemp = "";

	for (int i = 0; i < info.size(); i++)
	{
		// ���ڿ� �Ľ��Ұ�
		istringstream stt(info[i]);

		// ������ �������� ���ڿ��� �Ľ�
		stt >> s[0] >> s[1] >> s[2] >> s[3] >> sTemp;

		addCases(s, (int)stoi(sTemp));
	}

	for (auto iter = hashScores.begin(); iter != hashScores.end(); iter++)
	{
		sort(iter->second.begin(), iter->second.end());
	}

	for (int i = 0; i < query.size(); i++)
	{
		int score;

		istringstream stt(query[i]);
		stt >> s[0] >> sTemp >> s[1] >> sTemp >> s[2] >> sTemp >> s[3] >> sTemp;
		score = stoi(sTemp);

		vector<int> vecTemp = hashScores[s[0] + s[1] + s[2] + s[3]];

		if (vecTemp.size() != 0)
		{
			// lower_bound : ���� ���ͷ����� ~ �� ���ͷ����� ���̿��� value �̻��� ���� ������ ���ͷ����͸� ��ȯ�ϰ� �ȴ�.		
			// �� ������ Binary Search�� �̷������ ������ �׻� lower_bound�� ���۽�Ű�� ���ؼ��� �ش��ϴ� ���ʹ� ���ĵǾ� �־�� �Ѵ�.	
			// �̶� ���ͷ����͸� ��ȯ���� �ʰ� �ε����� ��ȯ �ޱ� ���ؼ���
			// lower_bound(~) - vector.begin()�� �ϰ� �ȴٸ� �ε����� ��ȯ ���� �� �ִ�.			
			auto iter = lower_bound(vecTemp.begin(), vecTemp.end(), score);
			answer.push_back(vecTemp.size() - (iter - vecTemp.begin()));
		}

		else
		{
			answer.push_back(0);
		}
	}

	return answer;
}

//vector<int> vecAnswer;
//vector<int> solution(vector<string> info, vector<string> query)
//{
//	vector<int> answer;
//
//	vector<string> vecInfoString[5];
//
//	// ������ ����
//	for (int i = 0; i < info.size(); i++)
//	{
//		string sTemp = "";
//		int index = 0;
//
//		for (int j = 0; j < info[i].size(); j++)
//		{
//			if (info[i][j] == ' ')
//			{
//				vecInfoString[index].push_back(sTemp);
//				sTemp = "";
//				index++;
//				continue;
//			}
//
//			sTemp += info[i][j];
//
//			if (j == info[i].size() - 1)
//			{
//				vecInfoString[index].push_back(sTemp);
//			}
//		}
//	}
//
//	vector<string> vecQueryString[5];
//
//	// ����
//	for (int i = 0; i < query.size(); i++)
//	{
//		string sTemp = "";
//		int index = 0;
//		memset(vecQueryString, NULL, sizeof(vecQueryString));
//
//		for (int j = 0; j < query[i].size(); j++)
//		{
//			if (query[i][j] == ' ')
//			{
//				if (sTemp == "and")
//				{
//					sTemp = "";
//					continue;
//				}
//
//				vecQueryString[index].push_back(sTemp);
//				sTemp = "";
//				index++;
//				continue;
//			}
//
//			sTemp += query[i][j];
//
//			if (j == query[i].size() - 1)
//			{
//				vecQueryString[index].push_back(sTemp);
//			}
//		}		
//		
//		int nValue = 0;
//		int idx = 0;
//		for (int k = 0; k < vecInfoString->size(); k++)
//		{
//			int InfoValue = stoi(vecInfoString[4][k]);
//			int QueryValue = stoi(vecQueryString[4][0]);			
//
//			if (   ((vecInfoString[0][k] == vecQueryString[0][0]) || (vecQueryString[0][0] == "-"))
//				&& ((vecInfoString[1][k] == vecQueryString[1][0]) || (vecQueryString[1][0] == "-"))
//				&& ((vecInfoString[2][k] == vecQueryString[2][0]) || (vecQueryString[2][0] == "-"))
//				&& ((vecInfoString[3][k] == vecQueryString[3][0]) || (vecQueryString[3][0] == "-"))				
//				&& (InfoValue >= QueryValue))
//			{
//				nValue++;
//			}
//		}
//
//		if (nValue >= 1)
//		{
//			answer.push_back(nValue);
//		}
//	}
//
//	return answer;
//}

int main()
{
	auto Answer = solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" }, { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });

	for (int i = 0; i < Answer.size(); i++)
	{
		cout << Answer[i] << " ";
	}

	return 0;
}