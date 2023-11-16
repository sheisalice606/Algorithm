#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
using namespace std;

int T, N;
vector<string> Temp;

void Dfs(int Count, int Curr, int Sum, string S) {

	if (Count == N)
	{
		if (Sum == 0)
			Temp.push_back(S);
		return;
	}

	//' '
	if (Count == N - 1)
	{
		//+
		Dfs(Count + 1, 0, Sum + Curr + Count + 1, S + "+" + to_string(Count + 1));

		//-
		Dfs(Count + 1, 0, Sum + Curr - (Count + 1), S + "-" + to_string(Count + 1));


		// ' '
		if(Curr > 0)
			Dfs(Count + 1, 0, Sum + (Curr * 10) + (Count + 1), S + " " + to_string(Count + 1));
		else
			Dfs(Count + 1, 0, Sum + (Curr * 10) - (Count + 1), S + " " + to_string(Count + 1));
	}
	else
	{
		//+
		Dfs(Count + 1, (Count + 1), Sum + Curr, S + "+" + to_string(Count + 1));

		//-
		Dfs(Count + 1, -1 * (Count + 1), Sum + Curr, S + "-" + to_string(Count + 1));

		// ' '
		if (Curr > 0)
			Dfs(Count + 1, Curr * 10 + (Count + 1), Sum, S + " " + to_string(Count + 1));
		else
			Dfs(Count + 1, Curr * 10 - (Count + 1), Sum, S + " " + to_string(Count + 1));
	}
}

int main() {

	cin >> T;
	while (T--)
	{
		cin >> N;
		Dfs(1, 1, 0, "1");
		sort(Temp.begin(), Temp.end());


		for (auto s : Temp)
		{
			cout << s << '\n';
		}

		cout << endl;
		Temp.clear();
	}
}