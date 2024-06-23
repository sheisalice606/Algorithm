#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, L, R;
int Map[51][51];
int Visit[51][51];
int Temp[51][51];

int Cnt = 0; // 연합 나라 수
int Sum = 0; // 연합 총 인구 수
vector<pair<int, int>> Vector; // 연합 나라 좌표 저장

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Clear_Visit() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Visit[i][j] = 0;
		}
	}
}

bool Cmp() { // Map 과 Temp 가 같으면 true 를 반환한다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Map[i][j] != Temp[i][j]) return false;
		}
	}
	return true;
}

void Sync() { // Temp 값을 Map 값으로 동기화 시킨다.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Temp[i][j] = Map[i][j];
		}
	}
}


void Input() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
			Temp[i][j] = Map[i][j];
		}
	}
}

void Dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > N) continue; // 범위 초과
		if (Visit[nx][ny] == 1) continue;					// 방문 전적 있음

		int Gap = abs(Map[x][y] - Map[nx][ny]);
		if (Gap  < L || Gap > R) continue;					// 인구 차이 범위 초과

		Cnt++;						  // 연합 나라 추가
		Sum += Map[nx][ny];			  // 연합 총 인구수 추가
		Vector.push_back({ nx, ny }); // 연합 좌표 저장

		Visit[nx][ny] = 1;
		Dfs(nx, ny);
	}

}


int main() {

	int Move = 0;

	Input();

	// 이 반복문이 다 돌면 1회의 인구이동이 마무리된다.

	while (true) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (Visit[i][j] == 0) {
					Dfs(i, j);

					for (int k = 0; k < Vector.size(); k++) {
						// DFS 좌표 갱신
						int x = Vector[k].first;
						int y = Vector[k].second;
						Map[x][y] = Sum / Cnt;
					}
					Vector.clear();

					Sum = 0;
					Cnt = 0;

				}
			}
		}

		Move++; // 이동 횟수 증가

		if (Cmp() == true) {
			cout << Move - 1 << '\n';
			break;
		}

		Sync();
		Clear_Visit();

	}
}