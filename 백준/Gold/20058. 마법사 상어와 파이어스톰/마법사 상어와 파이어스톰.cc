#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N;
int Map[200][200];
int Visit[200][200];
vector<int> Query;

int Sum;
int Max;
int Area = 0; //얼음 덩어리 세기 용도

struct Position {
	int x;
	int y;
	int m;
};
vector<Position> Vector;
vector<pair<int, int>> Melt_Position;

void Input() {
	int Exp, Q;
	cin >> Exp >> Q;
	N = pow(2, Exp);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	for (int i = 1; i <= Q; i++)
	{
		int E;
		cin >> E;
		Query.push_back(E);
	}
}

void Melt_State(int x, int y) {
	int Cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

		if (Map[nx][ny] > 0) Cnt++;
	}
	if (Cnt < 3 && Map[x][y] > 0)
	{
		Melt_Position.push_back({ x, y });
	}
}

void Rotation(int x, int y, int Size) {

	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			int nx = x + j;
			int ny = y + Size - (i + 1);
			Vector.push_back({ nx, ny, Map[x + i][y + j] });
		}
	}

	for (auto E : Vector)
	{
		Map[E.x][E.y] = E.m;
	}

	Vector.clear();
}


void Dfs(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
		if (Visit[nx][ny] == 1) continue;
		if (Map[nx][ny] < 1) continue;

		Visit[nx][ny] = 1;
		Area++;
		Dfs(nx, ny);
	}
}


int main()
{
	Input();
	for (int Exp : Query)
	{
		int Size = pow(2, Exp);
		//맨 위의 좌표
		for (int i = 1; i <= N; i += Size)
		{
			//맨 왼쪽의 좌표
			for (int j = 1; j <= N; j += Size)
			{
				Rotation(i, j, Size);
			}
		}

		//Melt_Position 에 좌표 삽입
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				Melt_State(i, j);
			}
		}

		//Melt_Position 좌표 얼음 녹이기
		for (auto E : Melt_Position)
		{
			int px = E.first;
			int py = E.second;
			Map[px][py]--;
		}

		Melt_Position.clear();
		//초기화


	}


	//남아있는 얼음의 총 합
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Sum += Map[i][j];
		}
	}


	//가장 큰 얼음덩어리 넓이 구하기
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Visit[i][j] == 1) continue;
			if (Map[i][j] < 1) continue;
			
			//영역 체크, 넓이 + 1
			Visit[i][j] = 1;
			Area++;

			//탐색 후 최댓값 갱신
			Dfs(i, j);
			Max = max(Max, Area);

			//초기화
			Area = 0;
		}
	}

	cout << Sum << '\n';
	cout << Max << '\n';

}