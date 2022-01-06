#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;	
	int Size_Unique = 0;
	int Size_Half = nums.size() / 2;

	sort(nums.begin(), nums.end());

	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	Size_Unique = nums.size();

	answer = min(Size_Half, Size_Unique);

	return answer;
}

int main()
{
	cout << solution({ 3,1,2,3 }) << '\n';		// 2
	cout << solution({ 3,3,3,2,2,4 }) << '\n';	// 3
	cout << solution({ 3,3,3,2,2,2 }) << '\n';	// 2

	return 0;
}