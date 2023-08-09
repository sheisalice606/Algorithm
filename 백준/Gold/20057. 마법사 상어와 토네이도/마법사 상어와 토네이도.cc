#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N;
int sx, sy;
int Map[500][500];

//토네이도의 진행 방향 순서
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int Ans = 0;
int A;

void Input() {
	cin >> N;
	sx = N / 2 + 1;
	sy = N / 2 + 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
}

void Check(int x, int y, int p, int Total) {

	int sand = Total * p / 100;
	//소수점 아래는 버린다.

	if (x < 1 || y < 1 || x > N || y > N) {
		Ans += sand;
		A -= sand;
	}
	else {
		Map[x][y] += sand;
		A -= sand;
	}
}

void Sand(int x, int y, int Dir) {

	int Total = Map[x][y]; //해당 칸에 있던 모래의 양
	A = Total;
	Map[x][y] = 0;

	if (Dir == 0)
	{
		Check(x - 1, y + 1, 1, Total);
		Check(x + 1, y + 1, 1, Total);

		Check(x - 2, y, 2, Total);
		Check(x + 2, y, 2, Total);

		Check(x, y - 2, 5, Total);

		Check(x - 1, y, 7, Total);
		Check(x + 1, y, 7, Total);

		Check(x - 1, y - 1, 10, Total);
		Check(x + 1, y - 1, 10, Total);

		int a_x = x;
		int a_y = y - 1;
		if (a_x < 1 || a_y < 1 || a_x > N || a_y > N)
		{
			Ans += A;
		}
		else
		{
			Map[a_x][a_y] += A;
		}
	}
	else if (Dir == 2)
	{
		Check(x - 1, y - 1, 1, Total);
		Check(x + 1, y - 1, 1, Total);

		Check(x - 2, y, 2, Total);
		Check(x + 2, y, 2, Total);

		Check(x, y + 2, 5, Total);

		Check(x - 1, y, 7, Total);
		Check(x + 1, y, 7, Total);

		Check(x - 1, y + 1, 10, Total);
		Check(x + 1, y + 1, 10, Total);

		int a_x = x;
		int a_y = y + 1;
		if (a_x < 1 || a_y < 1 || a_x > N || a_y > N)
		{
			Ans += A;
		}
		else
		{
			Map[a_x][a_y] += A;
		}
	}
	else if (Dir == 1)
	{
		int one_x_1 = x - 1;
		int one_y_1 = y - 1;
		Check(one_x_1, one_y_1, 1, Total);

		int one_x_2 = x - 1;
		int one_y_2 = y + 1;
		Check(one_x_2, one_y_2, 1, Total);

		int two_x_1 = x;
		int two_y_1 = y - 2;
		Check(two_x_1, two_y_1, 2, Total);

		int two_x_2 = x;
		int two_y_2 = y + 2;
		Check(two_x_2, two_y_2, 2, Total);

		int five_x = x + 2;
		int five_y = y;
		Check(five_x, five_y, 5, Total);

		int seven_x_1 = x;
		int seven_y_1 = y + 1;
		Check(seven_x_1, seven_y_1, 7, Total);

		int seven_x_2 = x;
		int seven_y_2 = y - 1;
		Check(seven_x_2, seven_y_2, 7, Total);

		int ten_x_1 = x + 1;
		int ten_y_1 = y + 1;
		Check(ten_x_1, ten_y_1, 10, Total);

		int ten_x_2 = x + 1;
		int ten_y_2 = y - 1;
		Check(ten_x_2, ten_y_2, 10, Total);

		int a_x = x + 1;
		int a_y = y;
		if (a_x < 1 || a_y < 1 || a_x > N || a_y > N)
		{
			Ans += A;
		}
		else
		{
			Map[a_x][a_y] += A;
		}
	}
	else if (Dir == 3)
	{
		int one_x_1 = x + 1;
		int one_y_1 = y - 1;
		Check(one_x_1, one_y_1, 1, Total);

		int one_x_2 = x + 1;
		int one_y_2 = y + 1;
		Check(one_x_2, one_y_2, 1, Total);

		int two_x_1 = x;
		int two_y_1 = y - 2;
		Check(two_x_1, two_y_1, 2, Total);

		int two_x_2 = x;
		int two_y_2 = y + 2;
		Check(two_x_2, two_y_2, 2, Total);

		int five_x = x - 2;
		int five_y = y;
		Check(five_x, five_y, 5, Total);

		int seven_x_1 = x;
		int seven_y_1 = y + 1;
		Check(seven_x_1, seven_y_1, 7, Total);

		int seven_x_2 = x;
		int seven_y_2 = y - 1;
		Check(seven_x_2, seven_y_2, 7, Total);

		int ten_x_1 = x - 1;
		int ten_y_1 = y + 1;
		Check(ten_x_1, ten_y_1, 10, Total);

		int ten_x_2 = x - 1;
		int ten_y_2 = y - 1;
		Check(ten_x_2, ten_y_2, 10, Total);

		int a_x = x - 1;
		int a_y = y;
		if (a_x < 1 || a_y < 1 || a_x > N || a_y > N)
		{
			Ans += A;
		}
		else
		{
			Map[a_x][a_y] += A;
		}
	}
}


void Move() {

	//거리, 방향
	int Dist = 1;
	int Dir = 0;

	//시작 토네이도 좌표
	int px = sx;
	int py = sy;

	while (true)
	{
		//같은 길이반큼 2번씩 이동함 : 방향은 다름
		for (int i = 0; i < 2; i++)
		{
			//Dist 길이만큼 1씩 이동함
			for (int k = 0; k < Dist; k++)
			{
				int nx = px + dx[Dir % 4];
				int ny = py + dy[Dir % 4];

				Sand(nx, ny, Dir % 4);

				px = nx;
				py = ny;
			}

			Dir++;
		}

		if (Dist == N - 1) break;
		else Dist++;
	}

	for (int k = 0; k < Dist; k++)
	{
		int nx = px + dx[0];
		int ny = py + dy[0];

		Sand(nx, ny, 0);

		px = nx;
		py = ny;
	}
	// 마지막 N-1 번의 이동

}

int main()
{
	Input();
	Move();
	cout << Ans << '\n';
}