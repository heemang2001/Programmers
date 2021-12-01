#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

//	P는 응시자가 앉아있는 자리를 의미합니다.
//	O는 빈 테이블을 의미합니다.
//	X는 파티션을 의미합니다.

bool bFlag;
bool bVisited[5][5];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(int x, int y, vector<string>& vecStr, int cnt)
{
	if (bFlag || cnt > 2)
	{
		return;
	}

	if (cnt > 0 && vecStr[x][y] == 'P')
	{
		bFlag = true;
		return;
	}

	bVisited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5 && !bVisited[next_x][next_y] && vecStr[next_x][next_y] != 'X')
		{
			DFS(next_x, next_y, vecStr, cnt + 1);
		}
	}
}

bool Solve(vector<string>& vecStr)
{
	vector<pair<int, int>> vecPeople;

	for (int i = 0; i < vecStr.size(); i++)
	{
		for (int j = 0; j < vecStr[i].size(); j++)
		{
			if (vecStr[i][j] == 'P')
			{
				vecPeople.push_back({ i,j });
			}
		}
	}

	for (auto People : vecPeople)
	{
		bFlag = false;
		memset(bVisited, false, sizeof(bVisited));
		DFS(People.first, People.second, vecStr, 0);

		if (bFlag == true)
		{
			return false;
		}
	}

	return true;
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;

	for (int i = 0; i < places.size(); i++)
	{
		if (Solve(places[i]) == true)
		{
			answer.push_back(1);
		}

		else
		{
			answer.push_back(0);
		}		
	}

	return answer;
}

int main()
{
	vector<int> vecAnswer = solution({	{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
										{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
										{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
										{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
										{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}	});

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}