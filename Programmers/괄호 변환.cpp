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

	// 1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.
	if (p.size() == 0)
	{
		return answer;
	}

	// ���� p�� �̹� "�ùٸ� ��ȣ ���ڿ�"�̶�� �״�� return �ϸ� �˴ϴ�.
	if (IsClear(p))
	{
		return p;
	}

	int cnt = 0;
	string u;
	string v;

	// 2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
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

	//	3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
	//	3 - 1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.
	if (IsClear(u))
	{
		return u + solution(v);
	}

	//	4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�.
	//	4 - 1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
	//	4 - 2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�.
	//	4 - 3. ')'�� �ٽ� ���Դϴ�.
	//	4 - 4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�.
	//	4 - 5. ������ ���ڿ��� ��ȯ�մϴ�.
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