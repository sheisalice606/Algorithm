#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int Map[9][9];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };


struct Cam {
	int x;
	int y;
	int num;
};

int Ans = 99999;
vector<Cam> Vector;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] > 0 && Map[i][j] < 6)
			{
				Vector.push_back({ i, j, Map[i][j]});
			}
		}
	}
}

//사각지대의 넓이 
int Make_Ans() {
	int Cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 0) Cnt++;
		}
	}
	return Cnt;
}

void Search(int x, int y, int num) {

	int Dir = num % 4;

	while (true)
	{
		int nx = x + dx[Dir];
		int ny = y + dy[Dir];

		x = nx;
		y = ny;

		if (nx < 1 || ny < 1 || nx > N || ny > M) return;	//범위 초과
		if (Map[nx][ny] == 6) return;						//벽
		if (Map[nx][ny] != 0) continue;						//다른 감시 카메라
		Map[nx][ny] = -1;
	}
}

void Solve(int Count) {

	if (Count == Vector.size())
	{
		int curr = Make_Ans();
		Ans = min(Ans, curr);
		return;
	}

	//카메라를 하나하나 짚어봄
	int px = Vector[Count].x;
	int py = Vector[Count].y;
	int pnum = Vector[Count].num;
	int Temp[9][9];
	
	for (int d = 0; d < 4; d++)
	{
		
		//변화 이전의 Map 상태를 기억하는 Temp 배열 선언
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				Temp[i][j] = Map[i][j];


		if (pnum == 1)
		{
			Search(px, py, d);
		}
		else if (pnum == 2)
		{
			Search(px, py, d);
			Search(px, py, d + 2);
		}
		else if (pnum == 3)
		{
			Search(px, py, d);
			Search(px, py, d + 1);
		}
		else if (pnum == 4)
		{
			Search(px, py, d);
			Search(px, py, d + 1);
			Search(px, py, d + 2);
		}
		else if (pnum == 5)
		{
			Search(px, py, d);
			Search(px, py, d + 1);
			Search(px, py, d + 2);
			Search(px, py, d + 3);
		}


		Solve(Count + 1);

		//복귀 후 Map 이전상태로 되돌리기
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= M; j++)
				Map[i][j] = Temp[i][j];
		
	}


}

int main() {
	Input();
	Solve(0);
	cout << Ans << '\n';
}