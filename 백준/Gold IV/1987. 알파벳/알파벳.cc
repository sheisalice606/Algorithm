#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int alpha[26] = { 0 };
char map[21][21] = { 0 };

int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };

int R, C;
int max_path = 0;


void dfs(int x, int y, int dist) {

	//alpha[map[x][y]] = 1; // 사용한 알파벳
	if (max_path < dist) max_path = dist;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= R && ny <= C) { // 범위 체크

			if (!alpha[(int)map[nx][ny] - 65]) { // 사용 안한 알파벳
				alpha[(int)map[nx][ny] - 65] = 1;
				dfs(nx, ny, dist+1);
				alpha[(int)map[nx][ny] - 65] = 0; // 상단의 재귀함수 완료 후 사용 알파벳 초기화 ★
			} 
		} 

	}



}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> R >> C;

	for (int i = 1; i <= R; i++) { // 세로 R 칸
		for (int j = 1; j <= C; j++) { // 가로 C 칸
			cin >> map[i][j];
		}
	}

	alpha[(int)map[1][1] - 65] = 1;
	dfs(1,1,1);
	cout << max_path << '\n';
    
    return 0;
}