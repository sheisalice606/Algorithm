#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int L, R, C;
int gL, gR, gC;
int sL, sR, sC;
int cnt = 0;
bool escape;

int visit[31][31][31];
char map[31][31][31];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };



void bfs(int x, int y, int z) {

	queue < pair<int, pair<int, int>>> q;
	q.push({ x, {y, z} });
	visit[x][y][z] = 1;

	while (!q.empty()) {

		int sz = q.size();

		for (int i = 0; i < sz; i++) {

			int px = q.front().first; // z
			int py = q.front().second.first; // y
			int pz = q.front().second.second; // x
			q.pop();

			if (px == gL && py == gR && pz == gC) {
				escape = true;
				return;
			}
			 

			for (int j = 0; j < 6; j++) {

				int nx = px + dx[j]; // z
				int ny = py + dy[j]; // y
				int nz = pz + dz[j]; // x

				if (nx > 0 && ny > 0 && nz > 0 && nx <= L && ny <= R && nz <= C)
				{
					if (map[nx][ny][nz] == '#') continue;

					if (map[nx][ny][nz] == '.' || map[nx][ny][nz] == 'E')
					{
						if (!visit[nx][ny][nz])
						{
							visit[nx][ny][nz] = 1;
							q.push({ nx, {ny, nz} });
						}
					}
				}

			}


		}
		cnt++;
	}
}

int main() { // 정점은 1 <= x <= N  


	cin.tie(NULL);

	while (true) {

		cin >> L >> R >> C;
		if (!L && !R && !C) break;



		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				for (int k = 1; k <= C; k++) {
					cin >> map[i][j][k]; // z y x
					if (map[i][j][k] == '#') {
						visit[i][j][k] = 1;
					}
					if (map[i][j][k] == 'E') {
						gL = i;
						gR = j;
						gC = k;
					}
					if (map[i][j][k] == 'S') {
						sL = i;
						sR = j;
						sC = k;
					}
				}
			}
		}

		bfs(sL, sR, sC);

		if (escape) {
			cout << "Escaped in " << cnt << " minute(s)." << endl;
		}
		else {
			cout << "Trapped!" << endl;
		}



		cnt = 0;
		escape = false;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
	}

}
