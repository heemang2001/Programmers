#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence)
{
	string answer = "";
	const string invalid = "invalid"; // "invalid" 출력용
	vector<string> words; // 하나의 규칙 상태가 끝날때마다 완성된 단어 이곳에 저장. 추후 하나씩 빼서 answer에 덧붙임
	vector<bool> checked(26); // 알파벳(인덱스)별로 특수문자로 쓰인 소문자 체크
	bool first_rule = false; // 현재 규칙 1 상태라면 true 
	bool second_rule = false; // 현재 규칙 2 상태라면 true
	char char_rule1 = NULL; // 현재 규칙 1 상태일 때 특수문자로 쓰이는 소문자 저장
	char char_rule2 = NULL; // 현재 규칙 2 상태일 때 특수문자로 쓰이는 소문자 저장
	string word = ""; // 아직 완성되지 않은 단어, 현재 규칙 상태에서 만들어나가는 중

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

		// 규칙 1상태도 아니고, 규칙 2상태도 아님, 즉 아무상태도 아님 ==> 새로운 단어 시작
		else
		{
			// 현재 단어가 대문자일 때
			if (isupper(sentence[i]))
			{
				// 현재 단어가 대문자면 규칙 1에 해당하는 단어 시작
				word += sentence[i];
				first_rule = true;

				// 다음 문자가 범위를 넘어설 때
				if (i + 1 == sentence.length())
				{
					first_rule = false; // 규칙 1 OFF
					words.push_back(word); // 단어 추가
					word = ""; // 리셋
				}

				// 다음 문자가 대문자일 때
				else if (isupper(sentence[i + 1]))
				{
					first_rule = false; // 규칙 1 OFF
					words.push_back(word); // 단어 추가
					word = ""; // 리셋
				}

				// 다음 문자가 소문자일 때
				else if (islower(sentence[i + 1]))
				{
					// 단어의 첫 소문자이니 방문 체크 (이미 이전 단어에서 쓰인적이 있는 특수문자인지) 
					if (checked[sentence[i + 1] - 'a'])
					{
						return invalid; // 있다면 invalid 리턴 후 종료
					}
					
					char_rule1 = sentence[i + 1]; // 현재 문자는 규칙 1 단어의 첫 문자. 소문자인 다음 문자가 규칙 1 의 특수문자가 될 수 있으므로 미리 저장해둠
					vector<int> pos; // 소문자인 다음 문자와 동일한 소문자들의 위치를 모두 pos 에 저장. pos.size()가 곧 해당 소문자의 개수가 된다.

					// 다음 문자부터 범위 끝까지 다음 문자(특수문자)와 동일한 문자의 인덱스를 pos 에 삽입한다.
					for (int j = i + 1; j < sentence.length(); ++j)
					{
						if (sentence[j] == char_rule1)
						{
							pos.push_back(j);
						}
					}

					// 1. 하나 밖에 없다는건 다음 문자인 소문자가 규칙 1 단어의 특수문자가 되야한다는 것. ex) OaO 
					// char_rule1 도 위에서 등록해놨으니 딱히 할게 없어서 continue (그래도 if문 따로 쓴 이유는
					// 규칙 2 단어의 특수문자가 되도록 하는 경우들을 전부 'else' 하나로 처리하기 위하여)
					if (pos.size() == 1)
					{
						continue;
					}

					// 2. 3개 이상인데 모두 대문자 사이사이에 인덱스 2 차이로 있을 때에도 다음 문자인 소문자가가 규칙 1 단어의 특수문자가 되야한다는 것. ex) AaBaCaDaE
					else if (pos.size() >= 3)
					{
						bool flag = true;

						for (int j = 1; j < pos.size(); ++j)
						{
							// 모든 인덱스가 전부 2 차이어야 함
							if (pos[i + 1] - pos[i] != 2)
							{
								flag = false;
								break;
							}
						}

						// 이곳에 해당
						if (flag)
						{
							continue;
						}
					}

					// 3. 위 두 경우를 제외한 나머지 경우들은 다음 문자인 소문자가 전부 규칙 2 혹은 규칙 1+2 단어의 특수문자가 되어야 한다. ex) OaOOa, OaObOa, ObOb
					else
					{
						first_rule = false;
						char_rule1 = NULL;
						words.push_back(word);
						word = "";
					}
				}
			}

			// 현재 문자 소문자일 때 (규칙 2 에 해당하는 단어 시작)
			if (islower(sentence[i]))
			{
				// 다른 단어에 사용된적이 있다면 “invalid”
				if (checked[sentence[i] - 'a'])
				{
					return invalid;
				}

				// 규칙 2 단어가 시작되야 하는데 이대로 끝나는 것이므로 “invalid”
				if (i + 1 == sentence.length())
				{
					return invalid;
				}

				// 규칙 2 의 소문자 두 개는 대문자 단어들을 감싸야 한다. 따라서 소문자가 연달아 나올 수 없다.
				else if (islower(sentence[i + 1]))
				{
					return invalid;
				}

				// 현재 문자는 규칙 2 단어의 첫 특수문자가 된다.
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