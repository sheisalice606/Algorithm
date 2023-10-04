#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int N, M;
vector<pair<int,int>> Map[50001]; // [ from ] { cost , to }
int Dist[50001];

void Search(int start) {
	priority_queue<pair<int, int>> PQ;
	Dist[start] = 0;
	PQ.push({ 0, start });
	// 초기 세팅

	while (!PQ.empty())
	{
		int curr = PQ.top().second;
		int cost = -PQ.top().first;
		PQ.pop();

		if (Dist[curr] < cost) continue;

		for (int i = 0; i < Map[curr].size(); i++)
		{
			int next = Map[curr][i].second;
			int next_cost = cost + Map[curr][i].first;

			if (Dist[next] > next_cost)
			{
				Dist[next] = next_cost;
				PQ.push({ -next_cost, next });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) Dist[i] = 987654321;
	for (int i = 1; i <= M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		Map[A].push_back({ C, B });
		Map[B].push_back({ C, A });
		//방향 그래프로 분할
	}

	Search(1);
	cout << Dist[N];
} 