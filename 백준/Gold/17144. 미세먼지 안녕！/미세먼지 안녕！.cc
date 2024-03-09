#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int N, M, T, Ans;
vector<pair<int, int>> Air;

int Map[50][50];
int Spread[50][50];
int Minus[50][50];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void Input() {
	cin >> N >> M >> T;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == -1)
			{
				Air.push_back({ i, j });
				Map[i][j] = 0;
			}
		}
}

//퍼져나가는 동작
void Make_Spread() {
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] > 0)
			{
				int Total = 0;
				for (int d = 0; d < 4; d++)
				{
					int nx = i + dx[d];
					int ny = j + dy[d];

					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (nx == Air[0].first && ny == Air[0].second) continue;
					if (nx == Air[1].first && ny == Air[1].second) continue;

					Spread[nx][ny] += (Map[i][j] / 5);
					Total += (Map[i][j] / 5);
				}
				Minus[i][j] = Total;
			}
		}
}

//배열 동기화
void Make_Oper() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (Minus[i][j] > 0)
			{
				Map[i][j] -= Minus[i][j];
				Minus[i][j] = 0;
			}
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (Spread[i][j] > 0)
			{
				Map[i][j] += Spread[i][j];
				Spread[i][j] = 0;
			}
		}
}

void Make_Rotation() {

	for (int i = Air[0].first; i > 0; i--)	
		Map[i][0] = Map[i - 1][0];
	Map[Air[0].first][Air[0].second] = 0;

	for (int i = 0; i < M - 1; i++)			
		Map[0][i] = Map[0][i + 1];
	for (int i = 0; i < Air[0].first; i++)	
		Map[i][M - 1] = Map[i + 1][M - 1];
	for (int i = M - 1; i > 0; i--)			
		Map[Air[0].first][i] = Map[Air[0].first][i - 1];
	//상단

	for (int i = Air[1].first; i < N - 1; i++)	
		Map[i][0] = Map[i + 1][0];
	Map[Air[1].first][Air[1].second] = 0;

	for (int i = 0; i < M - 1; i++)				
		Map[N - 1][i] = Map[N - 1][i + 1];
	for (int i = N - 1; i > Air[1].first; i--)	
		Map[i][M - 1] = Map[i - 1][M - 1];
	for (int i = M - 1; i > 0; i--)				
		Map[Air[1].first][i] = Map[Air[1].first][i - 1];
	//하단

}

int Make_Ans() {
	int Cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] > 0) Cnt += Map[i][j];
	return Cnt;
}

int main() {
	Input();
	while (T--)
	{
		Make_Spread();
		Make_Oper();
		Make_Rotation();
	}
	cout << Make_Ans();
}