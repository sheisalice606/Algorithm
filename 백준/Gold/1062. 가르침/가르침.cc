#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int N, K, Ans;
int Alpha[26];
string S[50];

void Input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> S[i];

	if (K < 5)
	{
		cout << 0;
		exit(0);
	}
}

int Make_Ans() {

	int Cnt = 0;
	for (int i = 0; i < N; i++)
	{
		string str = S[i];
		bool Flag = true;

		for (int j = 0; j < str.length(); j++)
		{
			if (Alpha[str[j] - 'a'] == 0)
			{
				Flag = false;
				break;
			}
		}

		if (Flag == true) Cnt++;
	}
	return Cnt;
}

void Dfs(int Count, int Idx) {

	if (Count == K - 5)
	{
		int Result = Make_Ans();
		Ans = max(Ans, Result);
		return;
	}
	
	for (int i = Idx; i < 26; i++)
	{
		if (Alpha[i] == 1) continue;
		Alpha[i] = 1;
		Dfs(Count + 1, i + 1);
		Alpha[i] = 0;
	}
}

int main() {

	Input();
	Alpha['a' - 'a'] = 1;
	Alpha['n' - 'a'] = 1;
	Alpha['t' - 'a'] = 1;
	Alpha['i' - 'a'] = 1;
	Alpha['c' - 'a'] = 1;

	Dfs(0, 0);
	cout << Ans;

}