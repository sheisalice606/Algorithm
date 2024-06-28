#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <stack>
#include <string>
using namespace std;

int N, M, X, Dist[1001], Go[1001], Back[1001];
vector<pair<int, int>> Node[1001];


void Input() {
	cin >> N >> M >> X;
	for (int i = 1; i <= M; i++) {
		int A, B, Cost;
		cin >> A >> B >> Cost;
		Node[A].push_back({ Cost, B });
	}
}

void Setting() {
	for (int i = 1; i <= N; i++) {
		Dist[i] = 2e9 + 1;
	}
}

void Search(int start) {
	priority_queue<pair<int, int>> PQ;
	Dist[start] = 0;
	PQ.push({ 0, start });
	//cost, to

	while (!PQ.empty()) {
		
		int curr = PQ.top().second;
		int cost = -PQ.top().first;
		PQ.pop();
		
		if (Dist[curr] < cost) continue;

		for (int i = 0; i < Node[curr].size(); i++) {
			int next = Node[curr][i].second;
			int next_cost = cost + Node[curr][i].first;

			if (Dist[next] > next_cost) {
				Dist[next] = next_cost;
				PQ.push({ -next_cost, next });
			}
		}
	}
}

int main() {
	
	Input();
	Setting();
	Search(X);	
	for (int i = 1; i <= N; i++) Back[i] = Dist[i];

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		Setting();
		Search(i);
		Go[i] = Dist[X];
	}

	int Ans = -1;
	for (int i = 1; i <= N; i++) {
		Ans = max(Ans, Go[i] + Back[i]);
	} 
	cout << Ans;

}