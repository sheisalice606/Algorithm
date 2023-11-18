#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int N, Ans;
int Map[101][101];
int Visit[101][101];

int dx[4] = { 0, 0, -1 };
int dy[4] = { -1, 1, 0 };
// 좌 -> 우 -> 상

int X, Y;

void Input() {
	cin >> N;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2)
			{
				X = i;
				Y = j;
			}
		}
}


void Clear() {
	memset(Map, 0, sizeof(Map));
	memset(Visit, 0, sizeof(Visit));
	Ans = 0;
	X = 0;
	Y = 0;
}

void Bfs() {

	queue<pair<int, int>> Q;
	Q.push({ X, Y });
	Visit[X][Y] = 1;

	while (!Q.empty())
	{
		int px = Q.front().first;
		int py = Q.front().second;
		Q.pop();

		if (px == 1)
		{
			Ans = py;
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > 100 || ny > 100) continue;
			if (Visit[nx][ny] == 1) continue;
			if (Map[nx][ny] == 0) continue;
            
			Visit[nx][ny] = 1;
			Q.push({ nx,ny });
			break;
		}

	}

}

int main() {
	
	int Turn = 1;
	while (Turn++ <= 10)
	{
		Clear();
		Input();
		Bfs();

		cout << "#" << N << ' ';
		cout << Ans - 1 << '\n';
	}
	
}