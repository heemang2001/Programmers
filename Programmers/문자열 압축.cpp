#include <string>
#include <vector>
#include <iostream>
#include <sstream> // 문자열 파싱 함수
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string s)
{
	int answer = 987654321;
	int Cutnum = 1;	
	int max_Cutnum = max(1, (int)(s.size() / 2));

	while (1)
	{
		if (Cutnum > max_Cutnum)
		{
			break;
		}
		
		int num = 1;
		string sTemp1 = "";
		string sTemp2 = "";
		string Answer_string = "";

		for (int i = 0; i < s.size(); i = i + Cutnum)
		{
			if (sTemp1 == "")
			{
				for (int j = i; j < i + Cutnum && j < s.size(); j++)
				{
					sTemp1 += s[j];
				}
			}

			else
			{
				for (int j = i; j < i + Cutnum && j < s.size(); j++)
				{
					sTemp2 += s[j];
				}

				if (sTemp1 == sTemp2)
				{
					num++;
					sTemp2 = "";
				}

				else
				{
					string strnum = "";

					if (num >= 2)
					{
						strnum = to_string(num) + sTemp1;
					}

					else
					{
						strnum = sTemp1;
					}
					
					sTemp1 = sTemp2;
					sTemp2 = "";
					Answer_string += strnum;
					num = 1;
				}

				if (i >= s.size() - 1)
				{
					string strnum = "";

					if (num >= 2)
					{
						strnum = to_string(num) + sTemp1;
					}

					else
					{
						strnum = sTemp1;
					}

					Answer_string += strnum;	
					sTemp1 = "";
					sTemp2 = "";
				}
			}
		}

		if (sTemp1 != "")
		{
			string strnum = "";

			if (num >= 2)
			{
				strnum = to_string(num) + sTemp1;
			}

			else
			{
				strnum = sTemp1;
			}

			Answer_string += strnum;
		}

		answer = min(answer, (int)Answer_string.size());
		Cutnum++;
	}

	return answer;
}

int main()
{
	//int Answer = solution("aabbaccc"); // 7
	int Answer = solution("a"); // 1

	return 0;
}