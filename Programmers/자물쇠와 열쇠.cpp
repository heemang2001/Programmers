#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void lotate(vector<vector<int>>& key)
{
	vector<vector<int>> vecTemp(key.size(), vector<int>(key.size()));

	for (int i = key.size()-1; i >= 0; i--)
	{
		for (int j = 0; j < key.size(); j++)
		{
			vecTemp[j][i] = key[key.size() - i - 1][j];
		}
	}

	key = vecTemp;
}

// (x,y)�� ���������� ���踦 �ڹ��迡 ���纻��.
bool sum(int x, int y, vector<vector<int>> key, vector<vector<int>> board)
{	
	int size_key = key.size();
	int size_Board = board.size();

	// key�� ���Ѵ�.
	for (int i = 0; i < size_key; i++)
	{
		for (int j = 0; j < size_key; j++)
		{
			board[x + i][y + j] += key[i][j];
		}
	}

	// �ڹ��� �κ� Ȯ��
	for (int i = size_key - 1; i < size_Board - size_key + 1; i++)
	{
		for (int j = size_key - 1; j < size_Board - size_key + 1; j++)
		{
			// 1�� �ƴϸ� false ����
			if (board[i][j] != 1)
			{
				return false;
			}
		}
	}

	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool answer = false;

	int size_Key = key.size();
	int size_Lock = lock.size();
	int size_Board = size_Lock + size_Key + size_Key - 2;

	vector<vector<int>> vecBoard(size_Board, vector<int>(size_Board, 0));

	// ���� lock�� ���� Board �߾ӿ� ���� �Ѵ�.
	for (int i = 0; i < size_Lock; i++)
	{
		for (int j = 0; j < size_Lock; j++)
		{
			vecBoard[i + size_Key - 1][j + size_Key - 1] = lock[i][j];
		}
	}

	// ȸ�� 4��
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < size_Key + size_Lock - 1; j++)
		{
			for (int k = 0; k < size_Key + size_Lock -1; k++)
			{
				// (j,k) ����ĭ���� �ڹ��� Ȩ�� ���纽
				if (sum(j, k, key, vecBoard))
				{
					answer = true;
					return answer;
				}
			}
		}

		// key �ð���� 90�� ȸ��
		lotate(key);
	}

	return answer;
}

int main()
{
	cout << solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} }) << '\n';	// true

	return 0;
}