#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N, M, Ans;
int Map[5][5];
int Visit[5][5];

int dx[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int dy[4][2] = { {-1, 0}, {-1, 0}, {0, 1}, {0, 1} };


void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}

void Dfs(int Count, int Sum) {
	if (Count == N * M) {
		Ans = max(Ans, Sum);
		return;
	}

	int x = Count / M;
	int y = Count % M;

	if (Visit[x][y] == 0) {
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d][0];
			int ny = y + dy[d][0];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (Visit[nx][ny] == 1) continue;

			int nnx = x + dx[d][1];
			int nny = y + dy[d][1];
			if (nnx < 0 || nny < 0 || nnx >= N || nny >= M) continue;
			if (Visit[nnx][nny] == 1) continue;


			Visit[x][y] = Visit[nx][ny] = Visit[nnx][nny] = 1;
			Dfs(Count + 1, Sum + (Map[nx][ny] + Map[nnx][nny] + 2 * Map[x][y]));
			Visit[x][y] = Visit[nx][ny] = Visit[nnx][nny] = 0;
		}
	}

	Dfs(Count + 1, Sum);

}

int main() {
	Input();
	Dfs(0, 0);
	cout << Ans;
}
