#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = -1;

	stack<char> stkAlpha;
	stkAlpha.push(s.front());

	for (int i = 1; i < s.size(); i++)
	{
		char curAlpha = s[i];

		if (!stkAlpha.empty() && curAlpha == stkAlpha.top())
		{
			stkAlpha.pop();
		}

		else
		{
			stkAlpha.push(curAlpha);
		}
	}

	if (stkAlpha.size() > 0)
	{
		answer = 0;
	}

	else
	{
		answer = 1;
	}

	return answer;
}

int main()
{
	cout << solution("baabaa") << '\n';	// 1
	cout << solution("cdcd") << '\n';	// 0

	return 0;
}

// 시간 초과
//int solution(string s)
//{
//	int answer = -1;
//
//	while (1)
//	{
//		bool bClear = false;
//
//		if (s.empty())
//		{
//			answer = 1;
//			break;
//		}
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == s[i + 1])
//			{
//				s.erase(s.begin() + i, s.begin() + i + 2);
//				bClear = true;
//			}
//		}
//
//		if (bClear == false)
//		{
//			answer = 0;
//			break;
//		}
//	}
//
//	return answer;
//}