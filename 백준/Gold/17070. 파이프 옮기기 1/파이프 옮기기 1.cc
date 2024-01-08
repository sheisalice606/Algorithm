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

int N, Ans;
int Map[17][17];

int dx_1[2] = { 0, 1 };
int dy_1[2] = { 1, 1 };
//직전 파이프가 가로인 상황

int dx_2[3] = { 0, 1, 1 };
int dy_2[3] = { 1, 1, 0 };
//직전 파이프가 대각선인 상황

int dx_3[2] = { 1, 1 };
int dy_3[2] = { 0, 1 };
//직전 파이프가 세로인 상황



void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];
	Map[1][1] = 1;
	Map[1][2] = 1;
}

void Print() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << ' ';
		}
		cout << endl;
	}
}

void Dfs(int x, int y, int D) {

	if (x == N && y == N)
	{
		Ans++;
		return;
	}


	if (D == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx_1[i];
			int ny = y + dy_1[i];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			//범위 초과

			if(i == 0)
			{
				if (Map[nx][ny] == 1) continue;

				Map[nx][ny] = 1;
				Dfs(nx, ny, 1);
				Map[nx][ny] = 0;
			}
			
			if (i == 1)
			{
				if (Map[nx][ny] == 1 || Map[nx - 1][ny] == 1 || Map[nx][ny - 1] == 1) continue;

				Map[nx][ny] = 1;
				Map[nx - 1][ny] = 1;
				Map[nx][ny - 1] = 1;

				Dfs(nx, ny, 2);

				Map[nx][ny] = 0;
				Map[nx - 1][ny] = 0;
				Map[nx][ny - 1] = 0;
			}

		}
	}
	
	
	if (D == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			int nx = x + dx_2[i];
			int ny = y + dy_2[i];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

			if (i == 0)
			{
				if (Map[nx][ny] == 1) continue;

				Map[nx][ny] = 1;
				Dfs(nx, ny, 1);
				Map[nx][ny] = 0;
			}
			
			if (i == 1)
			{
				if (Map[nx][ny] == 1 || Map[nx - 1][ny] == 1 || Map[nx][ny - 1] == 1) continue;

				Map[nx][ny] = 1;
				Map[nx - 1][ny] = 1;
				Map[nx][ny - 1] = 1;

				Dfs(nx, ny, i + 1);

				Map[nx][ny] = 0;
				Map[nx - 1][ny] = 0;
				Map[nx][ny - 1] = 0;
			}

			if (i == 2)
			{
				if (Map[nx][ny] == 1) continue;

				Map[nx][ny] = 1;
				Dfs(nx, ny, 3);
				Map[nx][ny] = 0;
			}

		}
	}

	if (D == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx_3[i];
			int ny = y + dy_3[i];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			
			if (i == 0)
			{
				if (Map[nx][ny] == 1) continue;

				Map[nx][ny] = 1;
				Dfs(nx, ny, 3);
				Map[nx][ny] = 0;
			}
			
			if (i == 1)
			{
				if (Map[nx][ny] == 1 || Map[nx - 1][ny] == 1 || Map[nx][ny - 1] == 1) continue;

				Map[nx][ny] = 1;
				Map[nx - 1][ny] = 1;
				Map[nx][ny - 1] = 1;

				Dfs(nx, ny, 2);

				Map[nx][ny] = 0;
				Map[nx - 1][ny] = 0;
				Map[nx][ny - 1] = 0;
			}

		}
	}

}

int main() {
	
	Input();
	Dfs(1, 2, 1);
	cout << Ans;

}