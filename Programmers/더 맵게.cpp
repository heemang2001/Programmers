#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 다 K이상인가?
bool Is_Kup_Scoville(priority_queue<int, vector<int>, greater<int>>& pq , int K)
{
	if (pq.top() < K)
	{
		return false;
	}

	return true;
}

int solution(vector<int> scoville, int K)
{
	int answer = 0;	
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (1)
	{
		if (Is_Kup_Scoville(pq, K) == true)
		{
			break;
		}

		answer++;

		int frontSco1 = pq.top();
		pq.pop();
		int frontSco2 = pq.top();
		pq.pop();

		int curScoville = frontSco1 + (frontSco2 * 2);
		pq.push(curScoville);

		if (pq.size() <= 1)
		{
			if (Is_Kup_Scoville(pq, K) == false)
			{
				answer = -1;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7); // 2

	return 0;
}