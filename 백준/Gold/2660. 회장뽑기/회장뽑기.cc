#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> Vector[51];
int N, Visit[51];
vector<pair<int, int>> Depth;
//깊이, 번호

void Input() {
	cin >> N;
	int A, B;
	while (true) {
		cin >> A >> B;
		if (A == -1 && B == -1) break;
		Vector[A].push_back(B);
		Vector[B].push_back(A);
	}
}

void Bfs(int start) {
	queue<pair<int, int>> Q;
	Q.push({ start, 0 });
	Visit[start] = 1;
	int Max = 0;

	while (!Q.empty())
	{
		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		Max = max(Max, time);

		for (int i = 0; i < Vector[curr].size(); i++)
		{
			int next = Vector[curr][i];
			if (Visit[next] == 1) continue;
			Visit[next] = 1;
			Q.push({ next, time + 1 });
		}
	}

	Depth.push_back({ Max, start });
}

int main() {
	Input();
	for (int i = 1; i <= N; i++)
	{
		Bfs(i);
		memset(Visit, 0, sizeof(Visit));
	}
	sort(Depth.begin(), Depth.end());
	cout << Depth[0].first << ' ';

	int n = 1;
	for (int i = 1; i < N; i++)
	{
		if (Depth[0].first == Depth[i].first) n++;
		else break;
	}
	cout << n << endl;

	for (int i = 0; i < n; i++)
		cout << Depth[i].second << ' ';
}