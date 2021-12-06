#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

bool IsPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}

	int last = num / 2;

	for (int i = 2; i < last; i++)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}

	return true;
}

int solution(vector<int> nums)
{
	int answer = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				int num = nums[i] + nums[j] + nums[k];

				if (IsPrime(num) == true)
				{
					answer++;
				}
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 1,2,3,4 }) << '\n';		// 1;
	cout << solution({ 1,2,7,6,4 }) << '\n';	// 4;

	return 0;
}