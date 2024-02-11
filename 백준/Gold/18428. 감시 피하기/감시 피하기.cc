#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
char Map[100][100];
int Visit[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void Print() {
	cout << "MAP : " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	cout << "Visit : " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Visit[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}


void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
}

void Spread(int x, int y) {
	Visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (nx >= 0 && ny >= 0 && nx <= N && ny <= N && Map[nx][ny] != 'O')
		{
			Visit[nx][ny] = 1;
			nx += dx[i];
			ny += dy[i];
		}
	}
}

bool Check() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 'T')
				Spread(i, j);
	//감시완료

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 'S' && Visit[i][j] == 1) 
				return false;
	//하나라도 잡힘

	return true;
	//모두 생존
}

void Dfs(int Count, int Idx) {
	if (Count == 3)
	{
		if (Check() == true)
		{
			cout << "YES" << endl;
			exit(0);
		}
		memset(Visit, 0, sizeof(Visit));
		return;
	}

	for (int i = Idx; i < N * N; i++)
	{
		int x = i / N;
		int y = i % N;
		if (Map[x][y] != 'X') continue;

		Map[x][y] = 'O';
		Dfs(Count + 1, i + 1);
		Map[x][y] = 'X';
	}
}

int main() {
	Input();
	Dfs(0, 0);
	cout << "NO" << endl;
}