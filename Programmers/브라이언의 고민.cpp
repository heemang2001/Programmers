#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence)
{
	string answer = "";
	const string invalid = "invalid"; // "invalid" ��¿�
	vector<string> words; // �ϳ��� ��Ģ ���°� ���������� �ϼ��� �ܾ� �̰��� ����. ���� �ϳ��� ���� answer�� ������
	vector<bool> checked(26); // ���ĺ�(�ε���)���� Ư�����ڷ� ���� �ҹ��� üũ
	bool first_rule = false; // ���� ��Ģ 1 ���¶�� true 
	bool second_rule = false; // ���� ��Ģ 2 ���¶�� true
	char char_rule1 = NULL; // ���� ��Ģ 1 ������ �� Ư�����ڷ� ���̴� �ҹ��� ����
	char char_rule2 = NULL; // ���� ��Ģ 2 ������ �� Ư�����ڷ� ���̴� �ҹ��� ����
	string word = ""; // ���� �ϼ����� ���� �ܾ�, ���� ��Ģ ���¿��� �������� ��

	for (int i = 0; i < sentence.length(); i++)
	{
		if (first_rule && second_rule)
		{
			if (isupper(sentence[i]))
			{
				word += sentence[i];

				if (i + 1 == sentence.length())
				{
					return invalid;
				}

				else if (isupper(sentence[i + 1]))
				{
					return invalid;
				}

				else if (char_rule1 != sentence[i + 1] && char_rule2 != sentence[i + 1])
				{
					return invalid;
				}
			}

			if (islower(sentence[i]))
			{
				if (char_rule2 == sentence[i])
				{
					first_rule = false;
					checked[char_rule1 - 'a'] = true;
					char_rule1 = NULL;

					second_rule = false;
					checked[char_rule2 - 'a'] = true;
					char_rule2 = NULL;

					words.push_back(word);
					word = "";

					continue;
				}

				if (i + 1 == sentence.length())
				{
					return invalid;
				}

				else if (islower(sentence[i + 1]))
				{
					return invalid;
				}
			}
		}

		else if (first_rule)
		{
			if (isupper(sentence[i]))
			{
				word += sentence[i];

				if (i + 1 == sentence.length())
				{
					first_rule = false;
					checked[char_rule1 - 'a'] = true;
					char_rule1 = NULL;
					words.push_back(word);
					word = "";
				}

				else if (isupper(sentence[i + 1]))
				{
					first_rule = false;
					checked[char_rule1 - 'a'] = true;
					char_rule1 = NULL;
					words.push_back(word);
					word = "";
				}

				else if (char_rule1 != sentence[i + 1])
				{
					first_rule = false;
					checked[char_rule1 - 'a'] = true;
					char_rule1 = NULL;
					words.push_back(word);
					word = "";
				}
			}

			if (islower(sentence[i]))
			{
				if (i + 1 == sentence.length())
				{
					return invalid;
				}

				else if (islower(sentence[i + 1]))
				{
					return invalid;
				}
			}
		}

		else if (second_rule)
		{
			if (isupper(sentence[i]))
			{
				word += sentence[i];

				if (i + 1 == sentence.length())
				{
					return invalid;
				}

				else if (islower(sentence[i + 1]) && char_rule2 != sentence[i + 1])
				{
					if (char_rule2 == sentence[i - 1])
					{
						if (checked[sentence[i + 1] - 'a'])
						{
							return invalid;
						}

						first_rule = true;
						char_rule1 = sentence[i + 1];
					}

					else
					{
						return invalid;
					}
				}
			}

			if (islower(sentence[i]))
			{
				second_rule = false;
				checked[char_rule2 - 'a'] = true;
				char_rule2 = NULL;
				words.push_back(word);
				word = "";
			}
		}

		// ��Ģ 1���µ� �ƴϰ�, ��Ģ 2���µ� �ƴ�, �� �ƹ����µ� �ƴ� ==> ���ο� �ܾ� ����
		else
		{
			// ���� �ܾ �빮���� ��
			if (isupper(sentence[i]))
			{
				// ���� �ܾ �빮�ڸ� ��Ģ 1�� �ش��ϴ� �ܾ� ����
				word += sentence[i];
				first_rule = true;

				// ���� ���ڰ� ������ �Ѿ ��
				if (i + 1 == sentence.length())
				{
					first_rule = false; // ��Ģ 1 OFF
					words.push_back(word); // �ܾ� �߰�
					word = ""; // ����
				}

				// ���� ���ڰ� �빮���� ��
				else if (isupper(sentence[i + 1]))
				{
					first_rule = false; // ��Ģ 1 OFF
					words.push_back(word); // �ܾ� �߰�
					word = ""; // ����
				}

				// ���� ���ڰ� �ҹ����� ��
				else if (islower(sentence[i + 1]))
				{
					// �ܾ��� ù �ҹ����̴� �湮 üũ (�̹� ���� �ܾ�� �������� �ִ� Ư����������) 
					if (checked[sentence[i + 1] - 'a'])
					{
						return invalid; // �ִٸ� invalid ���� �� ����
					}
					
					char_rule1 = sentence[i + 1]; // ���� ���ڴ� ��Ģ 1 �ܾ��� ù ����. �ҹ����� ���� ���ڰ� ��Ģ 1 �� Ư�����ڰ� �� �� �����Ƿ� �̸� �����ص�
					vector<int> pos; // �ҹ����� ���� ���ڿ� ������ �ҹ��ڵ��� ��ġ�� ��� pos �� ����. pos.size()�� �� �ش� �ҹ����� ������ �ȴ�.

					// ���� ���ں��� ���� ������ ���� ����(Ư������)�� ������ ������ �ε����� pos �� �����Ѵ�.
					for (int j = i + 1; j < sentence.length(); ++j)
					{
						if (sentence[j] == char_rule1)
						{
							pos.push_back(j);
						}
					}

					// 1. �ϳ� �ۿ� ���ٴ°� ���� ������ �ҹ��ڰ� ��Ģ 1 �ܾ��� Ư�����ڰ� �Ǿ��Ѵٴ� ��. ex) OaO 
					// char_rule1 �� ������ ����س����� ���� �Ұ� ��� continue (�׷��� if�� ���� �� ������
					// ��Ģ 2 �ܾ��� Ư�����ڰ� �ǵ��� �ϴ� ������ ���� 'else' �ϳ��� ó���ϱ� ���Ͽ�)
					if (pos.size() == 1)
					{
						continue;
					}

					// 2. 3�� �̻��ε� ��� �빮�� ���̻��̿� �ε��� 2 ���̷� ���� ������ ���� ������ �ҹ��ڰ��� ��Ģ 1 �ܾ��� Ư�����ڰ� �Ǿ��Ѵٴ� ��. ex) AaBaCaDaE
					else if (pos.size() >= 3)
					{
						bool flag = true;

						for (int j = 1; j < pos.size(); ++j)
						{
							// ��� �ε����� ���� 2 ���̾�� ��
							if (pos[i + 1] - pos[i] != 2)
							{
								flag = false;
								break;
							}
						}

						// �̰��� �ش�
						if (flag)
						{
							continue;
						}
					}

					// 3. �� �� ��츦 ������ ������ ������ ���� ������ �ҹ��ڰ� ���� ��Ģ 2 Ȥ�� ��Ģ 1+2 �ܾ��� Ư�����ڰ� �Ǿ�� �Ѵ�. ex) OaOOa, OaObOa, ObOb
					else
					{
						first_rule = false;
						char_rule1 = NULL;
						words.push_back(word);
						word = "";
					}
				}
			}

			// ���� ���� �ҹ����� �� (��Ģ 2 �� �ش��ϴ� �ܾ� ����)
			if (islower(sentence[i]))
			{
				// �ٸ� �ܾ �������� �ִٸ� ��invalid��
				if (checked[sentence[i] - 'a'])
				{
					return invalid;
				}

				// ��Ģ 2 �ܾ ���۵Ǿ� �ϴµ� �̴�� ������ ���̹Ƿ� ��invalid��
				if (i + 1 == sentence.length())
				{
					return invalid;
				}

				// ��Ģ 2 �� �ҹ��� �� ���� �빮�� �ܾ���� ���ξ� �Ѵ�. ���� �ҹ��ڰ� ���޾� ���� �� ����.
				else if (islower(sentence[i + 1]))
				{
					return invalid;
				}

				// ���� ���ڴ� ��Ģ 2 �ܾ��� ù Ư�����ڰ� �ȴ�.
				second_rule = true;
				char_rule2 = sentence[i];
			}
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		answer += (words[i] + " ");
	}

	answer.pop_back();

	return answer;
}

int main()
{
	cout << solution("HaEaLaLaObWORLDb") << '\n'; // HELLO WORLD
	cout << solution("SpIpGpOpNpGJqOqA") << '\n'; // SIGONG J O A
	cout << solution("AxAxAxAoBoBoB") << '\n';	  // invalid

	return 0;
}