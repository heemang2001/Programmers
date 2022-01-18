#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool bVisited[101][101];

void BFS(int x, int y, vector<vector<int>>& maps)
{
	queue<pair<int, int>> q;
	int maps_x = maps.size();
	int maps_y = maps.front().size();
	memset(bVisited, false, sizeof(bVisited));

	q.push({ 0, 0 });
	bVisited[0][0] = true;

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < maps_x && next_y < maps_y && maps[next_x][next_y] >= 1 && !bVisited[next_x][next_y])
			{
				bVisited[next_x][next_y] = true;
				maps[next_x][next_y] = maps[cur_x][cur_y] + 1;
				q.push({ next_x, next_y });
			}
		}
	}	
}

int solution(vector<vector<int>> maps)
{
	int answer = 0;
	int maps_x = maps.size();
	int maps_y = maps.front().size();

	BFS(0, 0, maps);

	if (maps[maps_x - 1][maps_y - 1] == 1)
	{
		answer = -1;
	}

	else
	{
		answer = maps[maps_x - 1][maps_y - 1];
	}

	return answer;
}

int main()
{
	cout << solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} }) << '\n';	// 11
	cout << solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1} }) << '\n';	// -1

	return 0;
}