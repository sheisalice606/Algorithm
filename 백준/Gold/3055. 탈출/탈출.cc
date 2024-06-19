#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N, M, Gx, Gy;
bool Flag = false;

queue<pair<int, int>> Q2;
char Map[51][51];
int Visit[51][51];

queue<pair<int, int>> Q;
int Water[51][51];


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
			//물
			if (Map[i][j] == '*') {
				Q.push({ i, j });
				Water[i][j] = 1;
			}
			//고슴도치
			if (Map[i][j] == 'S') {
				Q2.push({ i, j });
				Visit[i][j] = 1;
			}
			//비버의 굴
			if (Map[i][j] == 'D') {
				Gx = i;
				Gy = j;
			}
		}
	}
}

//1초의 물 퍼짐
//물이 퍼진 칸 Water[i][j] = 1
void Water_Spread() {

	int size = Q.size();
	
	while (size--) {
		int px = Q.front().first;
		int py = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (Water[nx][ny] == 1) continue;
			if (Map[nx][ny] == 'X' || Map[nx][ny] == 'D') continue;

			Water[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}

}

//1초 고슴도치 이동
int Bfs() {

	int size = Q2.size();
	if (size == 0) {
		return -1;
	}

	while (size--) {
		int px = Q2.front().first;
		int py = Q2.front().second;
		Q2.pop();

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (Visit[nx][ny] == 1) continue;
			if (Water[nx][ny] == 1) continue;
			if (Map[nx][ny] == 'X' ) continue;
			//방문하지 않았고, 물이 없는 칸으로만 전진한다.

			Visit[nx][ny] = 1;
			if (nx == Gx && ny == Gy) return 1;
			Q2.push({ nx, ny });
		}
	}

	return 0;
	//진전이 없음
}

void Print_Water() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << Water[i][j] << ' ';
		} cout << endl;
	}
}


int main() {
	Input();
	int Time = 1;
	while (true) {

		Water_Spread();
		int Result = Bfs();
	
		if (Result == 0) Time++;
		else if (Result == 1) {
			cout << Time;
			break;
		}
		else if (Bfs() == -1) {
			cout << "KAKTUS";
			break;
		}
	}
}