#include<iostream>
#include<queue>
using namespace std;

int K;
int W, H;

int map[201][201];
int visit[201][201][31];

queue<pair<pair<int, int>, pair<int, int>>> q; // (x, y), (K, second)

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int hx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int hy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };


void input() {
	cin >> K;
	cin >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}
}



void bfs() {

	while (!q.empty()) {

		int px = q.front().first.first;
		int py = q.front().first.second;

		int pK = q.front().second.first;
		int time = q.front().second.second;

		q.pop();


		if (px == H && py == W) {
			cout << time << endl;
			return;
		}





		for (int i = 0; i < 4; i++) {
			//monkey

			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > H || ny > W) continue;
			if (map[nx][ny] == 1 || visit[nx][ny][pK] == 1) continue;

			visit[nx][ny][pK] = 1;
			q.push({ {nx, ny}, {pK, time + 1} });

		}


		for (int i = 0; i < 8; i++) {

			int nx = px + hx[i];
			int ny = py + hy[i];

			if (nx < 1 || ny < 1 || nx > H || ny > W) continue;
			if (map[nx][ny] == 1 || visit[nx][ny][pK + 1] == 1 || pK + 1 > K) continue;

			visit[nx][ny][pK + 1] = 1;
			q.push({ {nx, ny}, {pK + 1, time + 1} });

		}


	}

	cout << -1 << endl;
	return;

}


int main() {

	input();
	
	q.push({ {1, 1}, {0, 0} });
	visit[1][1][0] = 1;

	bfs();

}

