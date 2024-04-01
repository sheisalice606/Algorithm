#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

int N, M, K;
char Map[10][10];
map<string, int> Hash;

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };


void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}

int Make_X(int n) {
	if (n == N) return 0;
	else if (n == -1) return N - 1;
	else return n;
}

int Make_Y(int n) {
	if (n == M) return 0;
	else if (n == -1) return M - 1;
	else return n;
}



void Bfs(int x, int y) {
	string st = "";
	st += Map[x][y];

	queue<pair<pair<int, int>, string>> Q;
	Q.push({ {x, y}, st });
	Hash[st]++;

	while (!Q.empty()) {
		int px = Q.front().first.first;
		int py = Q.front().first.second;
		string curr = Q.front().second;
		Q.pop();

		if (curr.length() == 5) {
			continue;
		}

		for (int i = 0; i < 8; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			nx = Make_X(nx);
			ny = Make_Y(ny);

			Hash[curr + Map[nx][ny]]++;
			Q.push({ {nx, ny}, curr + Map[nx][ny] });
		}

	}

}


int main() {
	Input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Bfs(i, j);
		}
	}

	for (int i = 0; i < K; i++) {
		string Temp;
		cin >> Temp;
		cout << Hash[Temp] << '\n';
	}
}
