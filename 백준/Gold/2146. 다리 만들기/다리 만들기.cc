#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int Map[101][101];
int Visit[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int Ans = 9999;

void Clear() {
	memset(Visit, 0, sizeof(Visit));
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 1)
			{
				Map[i][j] = -1;
			}
		}
	}
}

void Land(int x, int y, int Label) {
	
	queue<pair<int, int>> Q;
	Q.push({ x, y });
	Map[x][y] = Label;
	
	while (!Q.empty())
	{
		int px = Q.front().first;
		int py = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (Visit[nx][ny] == 1) continue;
			if (Map[nx][ny] == -1)
			{
				Visit[nx][ny] = 1;
				Map[nx][ny] = Label;
				Q.push({ nx, ny });
			}
			
		}
		
	}
}

int Bfs(int num) {
	
	queue<pair<pair<int, int>, int>> Q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] == num)
			{
				Q.push({ {i, j}, 0 });
				Visit[i][j] = 1;
			}
		}
	}
	// num 영역을 모두 push

	while (!Q.empty())
	{
		int px = Q.front().first.first;
		int py = Q.front().first.second;
		int time = Q.front().second;
		Q.pop();

		if (Map[px][py] != 0 && Map[px][py] != num)
		{
			return time - 1;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (Visit[nx][ny] == 1) continue;
			
			Visit[nx][ny] = 1;
			Q.push({ {nx, ny}, time + 1 });
		}
	}

	return -1;

}


int main() {

	Input();
	int Label = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Visit[i][j] == 0 && Map[i][j] == -1)
			{
				Visit[i][j] = 1;
				Land(i, j, Label);
				Label++;
			}
		}
	}

	Clear();
	//대륙 번호 지정

	for (int i = 1; i < Label; i++)
	{
		int Curr = Bfs(i);
		Ans = min(Ans, Curr);
		Clear();
	}

	cout << Ans;

}