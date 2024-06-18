#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> Vector[10001];
vector<int> Temp;

int N, Ans, Visit[10001];

void Input() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++)
	{
		int A, B, Cost;
		cin >> A >> B >> Cost;
		Vector[A].push_back({ B, Cost });
		Vector[B].push_back({ A, Cost });
	}
}

void Dfs(int x, int curr) {
	for (int i = 0; i < Vector[x].size(); i++)
	{
		if (Visit[Vector[x][i].first] == 1) continue;
		Visit[Vector[x][i].first] = 1;
		Dfs(Vector[x][i].first, curr + Vector[x][i].second);
	}
	Ans = max(Ans, curr);
}

int main() {
	Input();
	for (int i = 1; i <= N; i++)
	{
		Visit[i] = 1;
		Dfs(i, 0);
		memset(Visit, 0, sizeof(Visit));
	}
	cout << Ans << '\n';
}