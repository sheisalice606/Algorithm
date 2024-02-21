#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N;
int Map[126][126];
int Dist[126][126];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void search(int x, int y) {

	priority_queue<pair<int, pair<int, int>>> PQ;

	Dist[x][y] = Map[x][y];
	PQ.push({ -Map[x][y], {1, 1} });
	// 값, 좌표
	// 다익스트라에 Visit배열은 필요없다.

	while (!PQ.empty())
	{
		int curr = -PQ.top().first; //가장 큰 값

		int px = PQ.top().second.first;
		int py = PQ.top().second.second;
		PQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			
			//현재 위치에서 접근 가능한 노드
			int next = curr + Map[nx][ny];
			if (Dist[nx][ny] > next)
			{
				Dist[nx][ny] = next;
				PQ.push({ -next, {nx, ny} });
			}

		}

	}
	


}

int main() {
	int time = 1;
	while (true)
	{
		cin >> N;
		if (N == 0) break;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				cin >> Map[i][j];
				Dist[i][j] = 987654321;
			}//초기화


		search(1, 1);
		cout << "Problem " << time << ": " << Dist[N][N] << '\n';
		time++;
	}
}