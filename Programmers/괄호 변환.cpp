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

	// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
	if (p.size() == 0)
	{
		return answer;
	}

	// 만약 p가 이미 "올바른 괄호 문자열"이라면 그대로 return 하면 됩니다.
	if (IsClear(p))
	{
		return p;
	}

	int cnt = 0;
	string u;
	string v;

	// 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
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

	//	3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
	//	3 - 1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
	if (IsClear(u))
	{
		return u + solution(v);
	}

	//	4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
	//	4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
	//	4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
	//	4 - 3. ')'를 다시 붙입니다.
	//	4 - 4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
	//	4 - 5. 생성된 문자열을 반환합니다.
	answer = "(" + solution(v) + ")";
	
	for (int i = 1; i < u.size() - 1; i++)
	{
		answer += (u[i] == '(' ? ")" : "(");
	}

	return answer;
}

int main()
{
	//cout << solution("(()())()") << '\n';	// "(()())()"
	cout << solution(")(") << '\n';			// "()"
	cout << solution("()))((()") << '\n';	// "()(())()"

	return 0;
}