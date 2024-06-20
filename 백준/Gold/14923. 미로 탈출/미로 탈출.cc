#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N, M;
int Hx, Hy;
int Ex, Ey;
int Map[1001][1001];
int Visit[1001][1001][2];
//0 은 지팡이를 안쓴 상태로 진입
//1 은 지팡이를 쓴 상태로 진입


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct Status {
	int x;
	int y;
	int time;
	bool use;
};

void Input() {
	cin >> N >> M;
	cin >> Hx >> Hy;
	cin >> Ex >> Ey;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
		}
	}
}

int Bfs() {

	queue<Status> Q;
	Visit[Hx][Hy][0] = 1;
	Q.push({ Hx, Hy, 0, false });

	while (!Q.empty()) {
		int px = Q.front().x;
		int py = Q.front().y;
		int time = Q.front().time;
		bool use = Q.front().use;
		Q.pop();

		if (px == Ex && py == Ey) {
			return time;
		}


		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			
			//다음 칸이 빈칸
			if (Map[nx][ny] == 0) {
				//지팡이 사용X
				if (use == false && Visit[nx][ny][0] == 0) {
					Visit[nx][ny][0] = 1;
					Q.push({ nx, ny, time + 1, use });
				}
				//지팡이 사용O
				if (use == true && Visit[nx][ny][1] == 0) {
					Visit[nx][ny][1] = 1;
					Q.push({ nx, ny, time + 1, use });
				}
			}
			//다음 칸이 벽
			//지팡이를 사용하지 않은 경우만 전진이 가능하다.
			else {
				if (use == false && Visit[nx][ny][1] == 0) {
					Visit[nx][ny][1] = 1;
					Q.push({ nx, ny, time + 1, true });
				}
			}

		}

	}

	return -1;

}

int main() {
	Input();
	int Result = Bfs();
	cout << Result;
}