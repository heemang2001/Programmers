#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
	int answer = -1;

	sort(dungeons.begin(), dungeons.end());

	do 
	{
		int nTemp_k = k;
		int nTemp_Answer = 0;

		for (int i = 0; i < dungeons.size(); i++)
		{
			if (nTemp_k >= dungeons[i][0])
			{
				nTemp_k -= dungeons[i][1];
				nTemp_Answer++;
			}
		}

		answer = max(answer, nTemp_Answer);

	} while (next_permutation(dungeons.begin(), dungeons.end()));

	return answer;
}

int main()
{
	cout << solution( 80, { {80,20}, {50,40}, {30,10} }) << '\n';	// 3

	return 0;
}