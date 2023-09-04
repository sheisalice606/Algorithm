#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int Map[501][501];
int Visit[501][501];
int Ans = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
		}
	}
}

void Dfs(int x, int y, int Count, int Sum) {
	if (Count == 3)
	{
		Ans = max(Ans, Sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (Visit[nx][ny] == 1) continue;

		Visit[nx][ny] = 1;
		Dfs(nx, ny, Count + 1, Sum + Map[nx][ny]);
		Visit[nx][ny] = 0;
	}
}

int main() {
	Input();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			Visit[i][j] = 1;
			Dfs(i, j, 0, Map[i][j]);
			Visit[i][j] = 0;

			if (i - 1 >= 1 && i + 1 <= N && j + 1 <= M) Ans = max(Ans, Map[i][j] + Map[i + 1][j] + Map[i - 1][j] + Map[i][j + 1]);
			if (i - 1 >= 1 && i + 1 <= N && j - 1 >= 1) Ans = max(Ans, Map[i][j] + Map[i + 1][j] + Map[i - 1][j] + Map[i][j - 1]);
			if (j - 1 >= 1 && j + 1 <= M && i - 1 >= 1) Ans = max(Ans, Map[i][j] + Map[i][j - 1] + Map[i][j + 1] + Map[i - 1][j]);
			if (j - 1 >= 1 && j + 1 <= M && i + 1 <= N) Ans = max(Ans, Map[i][j] + Map[i][j - 1] + Map[i][j + 1] + Map[i + 1][j]);
		}
	}
	cout << Ans;
}