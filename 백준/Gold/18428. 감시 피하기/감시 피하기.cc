#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N;
char Map[6][6];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool Flag = false;


void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
}

bool Spread() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 'T') {

				for (int d = 0; d < 4; d++) {
					int px = i + dx[d];
					int py = j + dy[d];

					while (px >= 0 && py >= 0 && px < N && py < N && Map[px][py] != 'O') {
						if (Map[px][py] == 'S') return false;
						px += dx[d];
						py += dy[d];
					}
				}
			}
		}
	}
	return true;
}


//N*N 개 중 3개 고르기
void Dfs(int Count, int Idx) {

	if (Count == 3) {
		if (Spread() == true) {
			Flag = true;
		}
		return;
	}


	for (int i = Idx; i < N * N; i++) {
		int nx = i / N;
		int ny = i % N;

		if (Map[nx][ny] == 'X') {
			Map[nx][ny] = 'O';
			Dfs(Count + 1, i);
			if (Flag == true) return;
			Map[nx][ny] = 'X';
		}
	}
}


int main() {
	Input();
	Dfs(0, 0);
	if (Flag == true) cout << "YES" << endl;
	else cout << "NO" << endl;
}
