#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N, M, K, Ans, Visit[6][6];
char Map[6][6];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
		}
	}
}

void Dfs(int x, int y, int Count) {

	//cout << "x y : " << x << " , " << y << endl;
	//cout << Count << endl << endl;

	if (x == 1 && y == M) {
		if (Count == K) Ans++;
		//cout << Count << endl;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (Visit[nx][ny] == 1) continue;
		if (Map[nx][ny] == 'T') continue;

		Visit[nx][ny] = 1;
		Dfs(nx, ny, Count + 1);
		Visit[nx][ny] = 0;
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Visit[N][1] = 1;
	Dfs(N, 1, 1);
	cout << Ans;

}