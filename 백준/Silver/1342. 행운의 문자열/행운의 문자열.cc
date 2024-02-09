#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

string S;
map<char, int> Map;
int Ans, Len;


void Dfs(int Count, string Temp) {
	if (Count == Len)
	{
		Ans++;
		return;
	}

	for (auto it = Map.begin(); it != Map.end(); it++)
	{
		if (it->second == 0) continue;
		if (Temp.back() == it->first) continue;

		it->second--;
		Temp += it->first;
		Dfs(Count + 1, Temp);
		Temp.pop_back();
		it->second++;
	}
}

int main() {
	cin >> S;
	Len = S.length();

	for (int i = 0; i < S.length(); i++)
		Map[S[i]]++;

	string str = "";
	for (auto it = Map.begin(); it != Map.end(); it++)
	{
		if (it->second > 0)
		{
			it->second--;
			str += it->first;

			Dfs(1, str);

			str.pop_back();
			it->second++;
		}
	}
	cout << Ans;
}