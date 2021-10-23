#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<bool, int> IsContinue(vector<int>& vecOut)
{
	for (int i = 0; i < vecOut.size() - 1; i++)
	{
		if (vecOut[i] == vecOut[i + 1])
		{
			return make_pair(true, i);		
		}
	}

	return make_pair(false, -1);
}

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	vector<int> vecOut;

	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][moves[i] - 1] != 0)
			{
				vecOut.push_back(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}

	while (1)
	{
		if (vecOut.size() > 0)
		{
			auto curResult = IsContinue(vecOut);

			if (curResult.first == false)
			{
				break;
			}

			vecOut.erase(vecOut.begin() + curResult.second, vecOut.begin() + curResult.second + 2);
			answer += 2;
		}

		else
		{
			break;
		}
	}

	return answer;
}

int main()
{
	//cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 }) << '\n'; // 4
	cout << solution({ {5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5} }, { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 }) << '\n'; // 24

	return 0;
}