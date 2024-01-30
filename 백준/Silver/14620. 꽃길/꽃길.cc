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

int N, Ans = 2e9 + 1;
int Map[11][11];
int Flower[11][11];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];
}

void Spread(int x, int y, int Status) {
	Flower[x][y] = Status;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		Flower[nx][ny] = Status;
	}
}


bool Check(int x, int y) {
	if (Flower[x][y] == 1) return false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (Flower[nx][ny] == 1) return false;
	}
	return true;
}

int Make_Ans() {
	int Sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (Flower[i][j] == 1)
				Sum += Map[i][j];
	return Sum;
}


void Dfs(int Count) {
	if (Count == 3)
	{
		Ans = min(Ans, Make_Ans());
		return;
	}

	for(int i = 2; i <= N - 1; i++)
		for (int j = 2; j <= N - 1; j++)
		{
			if (Check(i, j) == false) continue;
			Spread(i, j, 1);
			Dfs(Count + 1);
			Spread(i, j, 0);
		}
}

int main() {
	Input();
	Dfs(0);
	cout << Ans;
}