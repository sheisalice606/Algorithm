#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int N, M;
int Map[200][200];
int Visit[200][200];
int Cnt[200][200];


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void Print() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << Cnt[i][j] << ' ';
		}
		cout << endl;
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> Map[i][j];
}

void Dfs(int x, int y) {

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (Visit[nx][ny] == 1) continue;

		if (Map[nx][ny] == 1)
		{
			Cnt[nx][ny]++;
			continue;
		}

		Visit[nx][ny] = 1;
		Dfs(nx, ny);
	}
}

int Cheeze() {
	int Cnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (Map[i][j] == 1)
				Cnt++;

	return Cnt;
}


int main() {
	
	Input();
	int Time = 0;

	while (true)
	{
		if (Cheeze() == 0)
		{
			cout << Time << endl;
			break;
		}
		//탈출 조건 확인

		Dfs(1, 1);
		//탐색

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				if (Map[i][j] == 1 && Cnt[i][j] >= 2)
					Map[i][j] = 0;
			}
		//치즈 녹이기

		//Print();

		memset(Visit, 0, sizeof(Visit));
		memset(Cnt, 0, sizeof(Cnt));
		Time++;
	}


}