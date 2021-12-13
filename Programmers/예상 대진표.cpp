#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	while (1)
	{
		if ((a + 1 == b && a % 2 == 1) || (b + 1 == a && b % 2 == 1))
		{
			answer++;
			break;
		}

		if (a % 2 == 0)
		{
			a /= 2;
		}

		else
		{
			a /= 2;
			a++;
		}

		if (b % 2 == 0)
		{
			b /= 2;
		}

		else
		{
			b /= 2;
			b++;
		}

		answer++;
	}

	return answer;
}

int main()
{
	cout << solution(8, 4, 7) << '\n';	// 3

	return 0;
}