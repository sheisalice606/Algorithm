#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define INF 987654321

int N;
int dist[125][125] = { 0 };
int map[125][125] = { 0 };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

priority_queue< pair<int, pair<int,int>>> pq; // cost, <x, y>

void dijkstra() {

	pq.push({ -map[0][0], {0, 0}});
	dist[0][0] = map[0][0];

	while (!pq.empty()) {

		int px = pq.top().second.first;
		int py = pq.top().second.second;
		int p_dist = -pq.top().first;
		pq.pop();

		if (dist[px][py] < p_dist) continue;

		for (int i = 0; i < 4; i++) {

			int nx = px + dx[i];
			int ny = py + dy[i];
			int n_dist = p_dist + map[nx][ny];

			if (nx >= 0 && ny >= 0 && nx <= N - 1 && ny <= N - 1) {
				if (dist[nx][ny] > n_dist) {
					dist[nx][ny] = n_dist;
					pq.push({ -n_dist, {nx, ny} });
				}
			}

		}

	}

}

int main() {

	int count = 1;

	while (true) {

		cin >> N;
		if (!N) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
				cin >> map[i][j];
			}
		}

		dijkstra();
		cout << "Problem " << count++ << ": " << dist[N - 1][N - 1] << endl;

		memset(dist, 0, sizeof(dist));
		memset(map, 0, sizeof(map));

	}

}