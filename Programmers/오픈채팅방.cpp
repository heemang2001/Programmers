#include <string>
#include <vector>
#include <iostream>
#include <sstream> // 문자열 파싱 함수
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;

	vector<string> vecFirst;
	vector<string> vecID;
	vector<string> vecNickName;	
	unordered_map<string, string> hash_IDNickName;

	for (int i = 0; i < record.size(); i++)
	{
		istringstream stt(record[i]);

		string sTemp1;
		string sTemp2;
		string sTemp3;

		stt >> sTemp1 >> sTemp2 >> sTemp3;

		vecFirst.push_back(sTemp1);
		vecID.push_back(sTemp2);

		if (sTemp1 == "Enter" || sTemp1 == "Change")
		{
			hash_IDNickName[sTemp2] = sTemp3;
		}		
	}

	for (int i = 0; i < vecFirst.size(); i++)
	{
		if (vecFirst[i] == "Enter")
		{
			string sTemp = hash_IDNickName[vecID[i]] + "님이 들어왔습니다.";
			answer.push_back(sTemp);
		}

		else if (vecFirst[i] == "Leave")
		{
			string sTemp = hash_IDNickName[vecID[i]] + "님이 나갔습니다.";
			answer.push_back(sTemp);
		}
	}

	return answer;
}

int main()
{
	vector<string> vecAnswer = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

	cout << "";

	return 0;
}