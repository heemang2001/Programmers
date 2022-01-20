#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool IsClear(string str)
{
	bool bReturn = false;

	stack<char> stkTemp;

	for (int i = 0; i < str.size(); i++)
	{
		char cur_char = str[i];

		if (!stkTemp.empty())
		{
			if (stkTemp.top() == '(' && cur_char == ')')
			{
				stkTemp.pop();
			}

			else
			{
				stkTemp.push(cur_char);
			}
		}

		else
		{
			stkTemp.push(cur_char);
		}
	}

	if (stkTemp.empty())
	{
		bReturn = true;
	}

	else
	{
		bReturn = false;
	}

	return bReturn;
}

string solution(string p)
{
	string answer = "";

	if (p.size() == 0)
	{
		return answer;
	}

	if (IsClear(p))
	{
		return p;
	}

	int cnt = 0;
	string u;
	string v;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == '(')
		{
			cnt++;
		}

		else
		{
			cnt--;
		}

		if (cnt == 0)
		{
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}

	if (IsClear(u))
	{
		return u + solution(v);
	}

	answer = "(" + solution(v) + ")";
	
	for (int i = 1; i < u.size() - 1; i++)
	{
		answer += (u[i] == '(' ? ")" : "(");
	}

	return answer;
}

int main()
{
	cout << solution("(()())()") << '\n';	// "(()())()"
	cout << solution(")(") << '\n';			// "()"
	cout << solution("()))((()") << '\n';	// "()(())()"

	return 0;
}