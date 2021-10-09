#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2)
{
	int answer = 0;

	// 다 대문자로
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

	vector<string> vecStr1;
	vector<string> vecStr2;

	// str1 2글자씩 나누기
	for (int i = 0; i < str1.size(); i++)
	{
		int next_index = i + 1;

		if (isalpha(str1[i]) && isalpha(str1[next_index]))
		{
			string sTemp = ""; 
			sTemp += str1[i];
			sTemp += str1[next_index];
			vecStr1.push_back(sTemp);
		}
	}

	// str2 2글자씩 나누기
	for (int i = 0; i < str2.size(); i++)
	{
		int next_index = i + 1;

		if (isalpha(str2[i]) && isalpha(str2[next_index]))
		{
			string sTemp = "";
			sTemp += str2[i];
			sTemp += str2[next_index];
			vecStr2.push_back(sTemp);
		}
	}
	
	if (vecStr1.size() == 0 && vecStr2.size() == 0)
	{
		return 65536;
	}

	// 교집합 합집합
	double common = 0;
	double combine = 0;

	for (int i = 0; i < vecStr1.size(); i++)
	{
		for (int j = 0; j < vecStr2.size(); j++)
		{
			if (vecStr1[i] == vecStr2[j])
			{
				common++;
				vecStr2.erase(vecStr2.begin() + j);
				break;
			}
		}
	}

	combine = vecStr1.size() + vecStr2.size();
	double double_Answer = (common / combine) * 65536;
	answer = double_Answer;

	return answer;
}

int main()
{
	//cout << solution("aaabb", "aabbb") << '\n'; // 
	//cout << solution("FRANCE", "french") << '\n'; // 16384
	//cout << solution("handshake", "shake hands") << '\n'; // 65536
	cout << solution("aa1+aa2", "AAAA12") << '\n'; // 43690
	//cout << solution("E=M*C^2", "e=m*c^2") << '\n'; // 65536

	return 0;
}