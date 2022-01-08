#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GCD(int num1, int num2)
{
	int nTemp;

	while (num2 != 0)
	{
		nTemp = num1 % num2;
		num1 = num2;
		num2 = nTemp;
	}

	return num1;
}

long long solution(int w, int h)
{
	long long answer = 1;

	long long W = w;
	long long H = h;

	answer = (W * H) - (W + H - GCD(w, h));

	return answer;
}

int main()
{
	cout << solution(8, 12) << '\n';	// 80

	return 0;
}