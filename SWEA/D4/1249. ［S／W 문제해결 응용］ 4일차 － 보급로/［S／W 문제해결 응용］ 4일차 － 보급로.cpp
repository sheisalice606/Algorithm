#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int T, N;
int Map[101][101];
int Dist[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void Search(int x, int y) {
	priority_queue<pair<int, pair<int, int>>> PQ;
	
	PQ.push({ 0,{x,y} });
	Dist[x][y] = 0;

	while (!PQ.empty())
	{
		int px = PQ.top().second.first;
		int py = PQ.top().second.second;
		int cost = -PQ.top().first;
		PQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			
			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (Dist[nx][ny] < 9999) continue;

			int next = cost + Map[nx][ny];

			if (Dist[nx][ny] > next)
			{
				Dist[nx][ny] = next;
				PQ.push({ -next, {nx, ny} });
			}
		}

	}
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string Temp;
		cin >> Temp;
		for (int j = 0; j < Temp.length(); j++)
		{
			Map[i][j + 1] = Temp[j] - '0';
		}
	}
}

void Clear() {
	memset(Map, 0, sizeof(Map));
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			Dist[i][j] = 9999;
}

void Print() {
	cout << "MAP : " << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Dist[i][j] << ' ';
		}
		cout << endl;
	} cout << endl;
}

int main() {
	
	cin >> T;
	int Turn = 1;
	while (Turn <= T)
	{
		Clear();
		Input();
		
		Search(1, 1);

		cout << "#" << Turn++ << ' ';
		cout << Dist[N][N] << endl;
	}
	
    return 0;
}