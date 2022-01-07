#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation)
{
	int answer = 0;
	int numOfRow = relation.size();
	int numOfCol = relation[0].size();

	vector<string> candKey;      // �ĺ�Ű ��� ��
	vector<bool> comb(numOfCol); // ���� ���ϴµ� ���� bool �迭
	vector<int> cols(numOfCol);  // colums �ε��� (���� �� ���)

	for (int i = 0; i < numOfCol; ++i)
	{
		cols[i] = i;
	}		

	for (int r = 1; r <= numOfCol; ++r)
	{
		fill(comb.begin(), comb.end(), true);
		for (int i = 0; i < r; ++i)
		{
			comb[i] = false;
		}
			
		do
		{
			// Column ���� �̱�
			string combCols = "";     // �̹��� ���� Column ����(stirng���� ����)

			for (int i = 0; i < numOfCol; ++i)
			{
				if (!comb[i])
				{
					combCols += to_string(cols[i]);
				}					
			}				

			// �ּҼ� �˻�
			bool isMinimal = true;
			if (!candKey.empty())
			{
				for (int i = 0; i < candKey.size(); ++i)
				{
					int count = 0;
					for (int j = 0; j < candKey[i].length(); ++j)
					{
						if (combCols.find(candKey[i][j]) != string::npos)
						{
							count++;
						}							
					}

					if (count == candKey[i].length())
					{
						isMinimal = false;
					}
				}
			}

			if (isMinimal == false)
			{
				continue;
			}

			// ���ϼ� �˻�
			bool isUnique = true;
			for (int i = 0; i < numOfRow - 1; ++i)
			{
				for (int j = i + 1; j < numOfRow; ++j)
				{
					if (relation[i][combCols[0] - '0'] == relation[j][combCols[0] - '0'])
					{
						if (combCols.length() == 1)
						{
							isUnique = false;
							break;
						}

						bool canDisc = false;
						for (int k = 1; k < combCols.length(); ++k)
						{
							if (relation[i][combCols[k] - '0'] != relation[j][combCols[k] - '0'])
							{
								canDisc = true;
							}							
						}

						if (!canDisc)
						{
							isUnique = false;
						}							
					}
				}
			}

			if (isUnique == false)
			{
				continue;
			}

			// �ĺ�Ű ã�� (�� �� �˻� ���)
			candKey.push_back(combCols);

		} while (next_permutation(comb.begin(), comb.end()));
	}

	answer = candKey.size();

	return answer;
}

int main()
{
	cout << solution(
		{
		{"100","ryan","music","2"},
		{"200","apeach","math","2"},
		{"300","tube","computer","3"},
		{"400","con","computer","4"},
		{"500","muzi","music","3"},
		{"600","apeach","music","2"}
		}) << '\n';	// 2

	return 0;
}