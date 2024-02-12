#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int R, C, K;
char Map[6][6];
int Visit[6][6];
vector<int> Vector;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int Ans;

void Input() {
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> Map[i][j];
}

void Dfs(int x, int y, int Count) {
	if (x == 1 && y == C)
	{
		if (Count == K) Ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
		if (Map[nx][ny] == 'T') continue;
		if (Visit[nx][ny] == 1) continue;

		Visit[nx][ny] = 1;
		Dfs(nx, ny, Count + 1);
		Visit[nx][ny] = 0;
	}
}

int main() {
	Input();
	Visit[R][1] = 1;
	Dfs(R, 1, 1);
	cout << Ans;
}