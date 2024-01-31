#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N, M, Cnt;
char Map[10001][501];
int Visit[10001][501];

int dx[3] = { -1, 0, 1 };
int dy[3] = { -1, -1, -1 };
bool Flag = true;

void Input() {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
		}
}

void Dfs(int x, int y) {

	if (y == 1)
	{
		Cnt++;
		Flag = false;
		return;
	}

	for (int i = 0; i < 3; i++)
	{	
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (Map[nx][ny] == 'x') continue;
		if (Visit[nx][ny] == 1) continue;
		
		Visit[nx][ny] = 1;
		Dfs(nx, ny);
		if (Flag == false) return;
		//Visit[nx][ny] = 0;
	}

}

int main() {

	Input();
	for (int i = 1; i <= N; i++)
	{
		Dfs(i, M);
		Flag = true;
	}
	cout << Cnt;
}