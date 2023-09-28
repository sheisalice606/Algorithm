#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int Map[101][101];
int Dist[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int Ans = 987654321;

void Print() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << Map[i][j] << ' ';
		} cout << endl;
	} cout << endl;
}


void Input() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		string s; 
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			Map[i][j + 1] = s[j] - '0';
		}
	}
}

void Bfs(int x, int y) {

	priority_queue < pair<int, pair<int, int>>> PQ;
	PQ.push({ -Map[x][y], {x, y} });
	Dist[x][y] = Map[x][y];

	while (!PQ.empty())
	{
		int curr = -PQ.top().first;
		int px = PQ.top().second.first;
		int py = PQ.top().second.second;
		PQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

			int next = curr + Map[nx][ny];
			if (Dist[nx][ny] > next)
			{
				Dist[nx][ny] = next;
				PQ.push({ -next, {nx, ny} });
			}
		}

	}
}

int main() {
	Input();
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			Dist[i][j] = 987654321;
	Bfs(1, 1);
	cout << Dist[N][M];
}
