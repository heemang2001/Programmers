#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
	int answer = 0;

	vector<string> vecTemp = { "A", "C", "F", "J", "M", "N", "R", "T" };

	sort(vecTemp.begin(), vecTemp.end());

	//{{왼쪽,오른쪽},{수식,숫자}}
	vector<pair<pair<string, string>, pair<string, int>>> vecData(n);

	for (int i = 0; i < n; i++)
	{
		vecData[i].first.first = data[i][0];
		vecData[i].first.second = data[i][2];
		vecData[i].second.first = data[i][3];
		vecData[i].second.second = data[i][4] - '0';
	}

	do
	{
		bool bClear[101] = {false,};
		memset(bClear, false, sizeof(bClear));

		for (int j = 0; j < n; j++)
		{
			if (j > 0 && bClear[j-1] == false)
			{
				break;
			}

			int nTemp1 = -1;
			int nTemp2 = -1;

			for (int i = 0; i < vecTemp.size(); i++)
			{
				if (vecTemp[i] == vecData[j].first.first)
				{
					nTemp1 = i;
				}

				else if (vecTemp[i] == vecData[j].first.second)
				{
					nTemp2 = i;
				}
			}
			
			// 두 문자사이 간격
			int nTemp3 = abs(nTemp1 - nTemp2) - 1;

			if (vecData[j].second.first == "=")
			{
				if (nTemp3 == vecData[j].second.second)
				{
					bClear[j] = true;
				}
			}

			else if (vecData[j].second.first == ">")
			{
				if (nTemp3 > vecData[j].second.second)
				{
					bClear[j] = true;
				}
			}

			else if (vecData[j].second.first == "<")
			{
				if (nTemp3 < vecData[j].second.second)
				{
					bClear[j] = true;
				}
			}
		}

		bool bOk = true;

		for (int i = 0; i < n; i++)
		{
			if (bClear[i] == true)
			{
				continue;
			}

			bOk = false;
			break;
		}

		if (bOk)
		{
			answer++;
		}

	} while (next_permutation(vecTemp.begin(), vecTemp.end()));

	return answer;
}

int main()
{
	cout << solution(2, { "N~F=0", "R~T>2" }) << '\n'; // 3648
	cout << solution(2, { "M~C<2", "C~M>1" }) << '\n'; // 0

	return 0;
}