#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#define INF 987654321

int N;

int height = 0; // 장마철 물의 높이
vector<int> h; // 영역의 갯수 저장 -> 최댓값을 뽑아낸다.

int map[101][101];
int visit[101][101];
int cnt = 0; // 영역의 갯수

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int rain) {

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
			if (!visit[nx][ny] && map[nx][ny] > rain) {
				visit[nx][ny] = 1;
				dfs(nx, ny, rain);
			}
		}

	}

}


int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	while (height <= 100) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visit[i][j] && map[i][j] > height) { // 지면이 물보다 높은 곳을 발견하면
					visit[i][j] = 1;
					cnt++;
					dfs(i, j, height);
				}
			}
		}


		h.push_back(cnt);

		cnt = 0;
		height++;
		memset(visit, 0, sizeof(visit));


	}

	int ans = *max_element(h.begin(), h.end());
	cout << ans;

}