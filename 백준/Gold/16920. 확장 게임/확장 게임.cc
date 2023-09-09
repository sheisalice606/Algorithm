#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, P;
int Map[1001][1001];
int Expand[1001][1001];
//영구 속성

int Visit[1001][1001];
//일회성 속성

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int S[10];
int Check[10];

int Ans[10];

void Input() {
	cin >> N >> M >> P;

	for (int i = 1; i <= P; i++)
	{
		cin >> S[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char C;
			cin >> C;

			if (C == '#')
			{
				Map[i][j] = -1;
			}
			else if (C == '.')
			{
				Map[i][j] = 0;
			}
			else
			{
				Map[i][j] = C - '0';
			}
		}
	}
}

void Bfs(int Turn, int S) {

	queue<pair<pair<int, int>, int>> Q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == Turn && Expand[i][j] == 0)
			{
				Q.push({ {i, j}, 0 });
				Expand[i][j] = 1;
				Visit[i][j] = 1;
			}
		}
	}
	//영역을 모두 Q 에 넣는다.

	while (!Q.empty())
	{
		int px = Q.front().first.first;
		int py = Q.front().first.second;
		int time = Q.front().second;
		Q.pop();


		if (time >= S)
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;	//범위초과
			if (Map[nx][ny] == -1) continue;						//벽
			if (Visit[nx][ny] == 1 || Expand[nx][ny] == 1) continue;						//중복 확장 불가장소

			if (Map[nx][ny] == 0)
			{
				Visit[nx][ny] = 1;
				Map[nx][ny] = Turn;

				Check[Turn]++;
				Q.push({ {nx, ny}, time + 1 });
			}
		}
	}

}

int Check_Sum() {
	int Sum = 0;
	for (int i = 1; i <= P; i++)
	{
		Sum += Check[i];
	}
	return Sum;
}

void Make_Ans() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] >= 1 && Map[i][j] <= P)
			{
				Ans[Map[i][j]]++;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	Input();

	while (true)
	{
		for (int i = 1; i <= P; i++)
		{
			Bfs(i, S[i]);
			memset(Visit, 0, sizeof(Visit));
		}

		if (Check_Sum() == 0)
		{
			break;
		}
		else
		{
			memset(Check, 0, sizeof(Check));
		}
	}

	Make_Ans();
	for (int i = 1; i <= P; i++)
	{
		cout << Ans[i] << ' ';
	}

}