#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321

vector<pair<int, int>> vecMap[51];
int arrLenth[51];

// 한 정점에서 모든 정점의 최단 거리를 구하는 알고리즘인 Dijkstra Algorithm
void Dijkstra(int K)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int pos;
	int distance;
	int next_pos;
	int next_distance;

	arrLenth[1] = 0;
	pq.push({ 1,0 });

	while (!pq.empty())
	{
		pos = pq.top().first;
		distance = pq.top().second;
		pq.pop();

		for (int i = 0; i < vecMap[pos].size(); i++)
		{
			next_pos = vecMap[pos][i].first;
			next_distance = vecMap[pos][i].second;

			if (arrLenth[next_pos] > arrLenth[pos] + next_distance)
			{
				arrLenth[next_pos] = arrLenth[pos] + next_distance;
				pq.push({ next_pos, next_distance });
			}
		}

	}
}

int solution(int N, vector<vector<int>> road, int K)
{
	int answer = 0;	

	for (int i = 1; i <= N; i++)
	{
		arrLenth[i] = INF;
	}

	memset(vecMap, 0, sizeof(vecMap));

	for (int i = 0; i < road.size(); i++)
	{
		int nTemp1 = road[i][0];
		int nTemp2 = road[i][1];
		int nTemp3 = road[i][2];

		vecMap[nTemp1].push_back(make_pair(nTemp2, nTemp3));
		vecMap[nTemp2].push_back(make_pair(nTemp1, nTemp3));
	}

	Dijkstra(K);

	for (int i = 1; i <= N; i++)
	{
		if (arrLenth[i] <= K)
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	cout << solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3) << '\n';				// 4
	cout << solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4) << '\n';	// 4

	return 0;
}