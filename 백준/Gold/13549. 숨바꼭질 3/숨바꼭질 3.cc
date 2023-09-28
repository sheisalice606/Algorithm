#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int Visit[100001];

void Bfs(int n) {
	
	deque<pair<int, int>> Q;
	Q.push_back({ n, 0 });

	while (!Q.empty())
	{
		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop_front();

		if (curr == M)
		{
			cout << time;
			return;
		}

		for (int next : {curr - 1, curr + 1, curr * 2})
		{
			if (next < 0 || next > 100000) continue;
			if (Visit[next] == 1) continue;

			Visit[next] = 1;
			if (next == curr * 2) Q.push_front({ next, time });
			else Q.push_back({ next, time + 1 });
		}
	}

}


int main() {
	cin >> N >> M;
	Bfs(N);
}