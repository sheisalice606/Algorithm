#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;
int N, M;
int Map[1001][1001];
int Visit[1001][1001];
int Dist[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Print() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << Dist[i][j] << ' ';
		} cout << endl;
	}
}

void Bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> Q;
	Q.push({ {x, y}, 0 });
	Dist[x][y] = 0;
	Visit[x][y] = 1;

	while (!Q.empty())
	{
		int px = Q.front().first.first;
		int py = Q.front().first.second;
		int time = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (Visit[nx][ny] == 1) continue; 
			if (Map[nx][ny] == 0) continue; // 갈 수 없는 땅

			Visit[nx][ny] = 1;
			Dist[nx][ny] = time + 1;
			Q.push({ {nx, ny}, time + 1 });
		}
	}
}

int main() {

	//Map 초기화
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
		}

	//거리 배열 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			Dist[i][j] = 0;

	//Bfs
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 2)
			{
				Bfs(i, j);
			}
		}

	for(int i = 1; i <= M; i++)
		for (int j = 1; j <= M; j++)
			if (Map[i][j] == 1 && Dist[i][j] == 0) Dist[i][j] = -1;

	Print();
}