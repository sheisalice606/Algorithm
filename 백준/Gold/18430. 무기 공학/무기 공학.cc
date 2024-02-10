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


int N, M, Ans = 0;
int Map[5][5];
int Visit[5][5];

vector<pair<int, int>> Vector;

int dx[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int dy[4][2] = { {-1, 0}, {-1, 0}, {0, 1}, {0, 1} };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
}

void Dfs(int Count, int Idx, int Sum, int G) {

	if (Count == G)
	{
		Ans = max(Ans, Sum);
		return;
	}

	for (int i = Idx; i <= N * M; i++)
	{
		int x = i / M;
		int y = i % M;
		if (Visit[x][y] == 1) continue;

		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d][0];
			int ny = y + dy[d][0];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (Visit[nx][ny] == 1) continue;


			int nnx = x + dx[d][1];
			int nny = y + dy[d][1];
			if (nnx < 0 || nny < 0 || nnx >= N || nny >= M) continue;
			if (Visit[nnx][nny] == 1) continue;


			Visit[x][y] = 1;
			Visit[nx][ny] = 1;
			Visit[nnx][nny] = 1;

			Dfs(Count + 1, i + 1, Sum + (2 * Map[x][y]) + Map[nx][ny] + Map[nnx][nny], G);

			Visit[x][y] = 0;
			Visit[nx][ny] = 0;
			Visit[nnx][nny] = 0;
		}
	}
}

int main() {
	Input();
	for (int i = 1; i <= (N * M) / 3; i++)
	{
		Dfs(0, 0, 0, i);
	}
	cout << Ans;
}