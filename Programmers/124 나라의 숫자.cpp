#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n)
{
	string answer = "";

	// 나머지 0,1,2 일때
	string temp[3] = { "4","1","2" };

	while (1)
	{
		if (n <= 0)
		{
			break;
		}

		answer = temp[n % 3] + answer;

		if (n % 3 == 0)
		{
			n = n / 3 - 1;
		}

		else
		{
			n = n / 3;
		}
	}

	return answer;
}

int main()
{
	//cout << solution(4) << '\n'; // 11
	cout << solution(17) << '\n'; // 122

	return 0;
}