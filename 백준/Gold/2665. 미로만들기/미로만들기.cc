#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N;
int Map[51][51], Visit[51][51];
int Cnt[51][51];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string Temp; cin >> Temp;
		for (int j = 0; j < N; j++)
		{
			Map[i + 1][j + 1] = Temp[j] - '0';
			Cnt[i + 1][j + 1] = 99;
		}
	}
}

void Print() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Cnt[i][j] << ' ';
		}
		cout << endl;
	}
}

int Bfs() {
	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	Cnt[1][1] = 0;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (Cnt[nx][ny] < Cnt[x][y] + 1) continue;

			if (Map[nx][ny] == 1) Cnt[nx][ny] = Cnt[x][y];
			if (Map[nx][ny] == 0) Cnt[nx][ny] = Cnt[x][y] + 1;

			Q.push({ nx, ny });
		}
	}

	return Cnt[N][N];
}

int main() {
	Input();
	cout << Bfs() << endl;
	//Print();
}