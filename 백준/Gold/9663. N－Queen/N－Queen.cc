#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

int N, Ans;
int Map[15];

bool Check(int N) {
	for (int i = 1; i < N; i++)
	{
		if (Map[i] == Map[N] || abs(N - i) == abs(Map[i] - Map[N])) return false;
	}
	return true;
}

void Dfs(int Count) {

	if (Count == N + 1)
	{
		Ans++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		Map[Count] = i;
		if (Check(Count) == true) Dfs(Count + 1);
		else Map[Count] = 0;
	}

	return;
}

int main() {

	cin >> N;
	Dfs(1);
	cout << Ans;
}