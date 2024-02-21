#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int T;
int N, D, C;
int Dist[100001];
vector<pair<int, int>> Vector[100001];

void Input() {
	cin >> N >> D >> C;
	for (int i = 0; i < D; i++)
	{
		int From, To, Cost;
		cin >> To >> From >> Cost;
		Vector[From].push_back({ Cost,To });
	}

	for (int i = 1; i <= N; i++)
		Dist[i] = 2e9 + 1;
}

void Clear() {
	for (int i = 1; i <= N; i++)
		Vector[i].clear();
	for (int i = 1; i <= N; i++)
		Dist[i] = 2e9 + 1;
}

void Search(int start) {
	priority_queue<pair<int, int>> PQ;
	PQ.push({ 0, start });
	Dist[start] = 0;
	//cost, to

	while (!PQ.empty())
	{
		int curr = PQ.top().second;
		int cost = -PQ.top().first;
		PQ.pop();

		for (int i = 0; i < Vector[curr].size(); i++)
		{
			int next = Vector[curr][i].second;
			int next_cost = cost + Vector[curr][i].first;
			if (Dist[next] > next_cost)
			{
				Dist[next] = next_cost;
				PQ.push({ -next_cost, next });
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		Input();
		Search(C);

		int Cnt = 0;
		int Time = 0;
		for (int i = 1; i <= N; i++)
			if (Dist[i] < 2e9 + 1)
			{
				Cnt++;
				Time = max(Time, Dist[i]);
			}

		cout << Cnt << ' ' << Time << endl;
		Clear();
	}

}