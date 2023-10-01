#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 987654321

int N, M;
int from, to, cost;

vector<pair<int, int>> e[1001]; // <cost, to> 
priority_queue<pair<int, int>> pq; // <cost, to>
int dist[1001] = { 0 }; // 출발 도시에서 도착지까지의 거리

void dijkstra(int start) {

	dist[start] = 0; 
	pq.push({ 0, start }); // 첫번째 넣는 성분 -> 자기 자신까지의 거리
	
	while (!pq.empty()) {

		int p_dist = -pq.top().first; // 최소비용
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < p_dist) continue; // 더 짧은 경우가 있는 경우 패스

		for (int i = 0; i < e[current].size(); i++) {

			int next = e[current][i].second;
			int n_dist = p_dist + e[current][i].first;
			if (dist[next] > n_dist) {
				dist[next] = n_dist;
				pq.push({ -n_dist, next });
			}

		}

	}


}

int main() {

	ios_base::sync_with_stdio(0); 
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < 1001; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		e[from].push_back({ cost, to }); // from -> {cost, to}
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start);
	cout << dist[end] << endl;

}