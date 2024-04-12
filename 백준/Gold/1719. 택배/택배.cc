#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M, Dist[201], History[201], Ans[201][201];
vector<pair<int, int>> Vector[201];
//cost, to

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B, Cost;
		cin >> A >> B >> Cost;
		Vector[A].push_back({ Cost, B });
		Vector[B].push_back({ Cost, A });
	}
}

void Search(int start) {
	priority_queue<pair<int, int>> PQ;
	PQ.push({ 0, start });
	for (int i = 1; i <= N; i++) Dist[i] = 1e9;
	Dist[start] = 0;

	while (!PQ.empty())
	{
		int curr = PQ.top().second;
		int cost = -PQ.top().first;
		PQ.pop();

		for (int i = 0; i < Vector[curr].size(); i++)
		{
			int next = Vector[curr][i].second;
			int next_cost = cost + Vector[curr][i].first;

			if (next_cost < Dist[next])
			{
				Dist[next] = next_cost;
				PQ.push({ -next_cost, next });
				History[next] = curr;
				//curr->next
			}
		}
	}
	//다익스트라

}

int main() {
	Input();

	for (int i = 1; i <= N; i++)
	{
		Search(i);
		for (int j = 1; j <= N; j++)
		{
			int Goal = j;

			while (History[Goal] != i && History[Goal] != 0)
			{
				Goal = History[Goal];
			}

			Ans[i][j] = Goal;
		}		
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j) cout << '-' << ' ';
			else cout << Ans[i][j] << ' ';
		}
		cout << endl;
	}

}