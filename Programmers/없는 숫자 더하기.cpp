#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers)
{
	int answer = 0;
	bool bNum[10] = { false, };
	
	for (int i = 0; i < numbers.size(); i++)
	{
		bNum[numbers[i]] = true;
	}

	for (int i = 0; i < sizeof(bNum); i++)
	{
		if (bNum[i] == false)
		{
			answer += i;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 1,2,3,4,6,7,8,0 }) << '\n';	// 14;
	cout << solution({ 5,8,4,0,6,7,9 }) << '\n';	// 6;

	return 0;
}