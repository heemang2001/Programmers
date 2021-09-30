#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";



	return answer;
}

int main()
{
	string Answer = solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });			// "09:00"
	string Answer = solution(2, 10, 2, { "09:10", "09:09", "08:00" });					// "09:09"
	string Answer = solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" });			// "08:59"
	string Answer = solution(1, 1, 5, { "00:01", "00:01", "00:01", "00:01", "00:01" });	// "00:00"
	string Answer = solution(1, 1, 1, { "23:59" });										// "09:00"
	string Answer = solution(10, 60, 45, { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59",
		"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" });				// "18:00"

	return 0;
}