#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int M;
int N;
int dx[4];
int dy[4];
bool bVisited[101][101];
int curColor;
int g_max_size_of_one_area;

void DFS(int x, int y, vector<vector<int>>& picture)
{
	if (x >= 0 && y >= 0 && x < M && y < N && bVisited[x][y] == false && picture[x][y] != 0 && picture[x][y] == curColor)
	{
		bVisited[x][y] = true;
		g_max_size_of_one_area++;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			DFS(next_x, next_y, picture);
		}
	}	
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	
	// 전역변수 초기화 부분
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
	memset(bVisited, false, sizeof(bVisited));
	curColor = 0;
	g_max_size_of_one_area = max_size_of_one_area;
	M = m;
	N = n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (bVisited[i][j] == false && picture[i][j] != 0)
			{		
				curColor = picture[i][j];
				DFS(i, j, picture);
				max_size_of_one_area = max(g_max_size_of_one_area, max_size_of_one_area);
				g_max_size_of_one_area = 0;
				number_of_area++;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}

int main()
{
	vector<int> vecAnswer = solution(6, 4, { {1, 1, 1, 0} ,{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} }); // 4, 5
}