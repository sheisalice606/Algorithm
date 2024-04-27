#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M, from, to, Ladder[101], Snake[101], Visit[101];
int dx[6] = { 1, 2, 3, 4, 5, 6 };

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> from >> to;
		Ladder[from] = to;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		Snake[from] = to;
	}
	//DEFAULT = 0
}

int Bfs() {
	queue<pair<int, int>> Q;
	Q.push({ 1, 0 });
	Visit[1] = 1;

	while (!Q.empty())
	{
		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop();

		if (curr == 100)
		{
			return time;
		}

		for (int i = 0; i < 6; i++)
		{
			int next = curr + dx[i];
			if (next > 100) continue;

			if (Ladder[next] != 0)
			{
				if (Visit[Ladder[next]] == 0)
				{
					Visit[Ladder[next]] = 1;
					Q.push({ Ladder[next], time + 1 });
				}
			}
			else if (Snake[next] != 0)
			{
				if (Visit[Snake[next]] == 0)
				{
					Visit[Snake[next]] = 1;
					Q.push({ Snake[next], time + 1 });
				}
			}
			else
			{
				if (Visit[next] == 0)
				{
					Visit[next] = 1;
					Q.push({ next, time + 1 });
				}
				
			}
		}
	}
	return -1;
}

int main() 
{
	Input();
	cout << Bfs();
}