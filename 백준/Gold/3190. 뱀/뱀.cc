#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int N, K, L;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int Map[101][101];
//오른, 아래, 왼, 위

queue<pair<int, char>> Q;
vector<pair<int, int>> Snake;


int Change_Dir(int curr, char Dir) {
	if (curr == 0)// 오른쪽
	{
		if (Dir == 'L') return 3; //위
		else if (Dir == 'D') return 1; //아래
	}
	else if (curr == 1)// 아래
	{
		if (Dir == 'L') return 0; //오른
		else if (Dir == 'D') return 2; //왼
	}
	else if (curr == 2)// 왼
	{
		if (Dir == 'L') return 1; //아래
		else if (Dir == 'D') return 3; //위
	}
	else if (curr == 3) // 위
	{
		if (Dir == 'L') return 2; // 왼
		else if (Dir == 'D') return 0; // 오른
	}
}


void Input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		Map[x][y] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int time;
		char dir;
		cin >> time >> dir;
		Q.push({ time, dir });
	}
}



int main() {
	Input();

	int Time = 1;
	int Dir = 0;
	
	Snake.push_back({ 1, 1 });
	//뱀의 가장 마지막

	while (true)
	{

		//cout << "현재 초 : " << Time << endl;
		//cout << "현재 방향 : " << Dir << endl << endl;

		//1. 일단 머리를 늘린다!!

		//뱀의 머리 좌표
		int px = Snake[Snake.size() - 1].first;
		int py = Snake[Snake.size() - 1].second;

		//다음 이동 좌표
		int nx = px + dx[Dir];
		int ny = py + dy[Dir];

		//범위 초과 체크
		if (nx < 1 || ny < 1 || nx > N || ny > N)
		{
			cout << Time << '\n';
			break;
		}

		//본체 충돌 체크
		bool Flag = true;
		for (int i = 0; i < Snake.size(); i++)
		{
			if (nx == Snake[i].first && ny == Snake[i].second)
			{
				Flag = false;
				break;
			}
		}
		if (Flag == false)
		{
			cout << Time << '\n';
			break;
		}

		//머리 늘림
		Snake.push_back({ nx, ny });


		//2. 사과 체크

		if (Map[nx][ny] == 2)
		{
			Map[nx][ny] = 0;
		}
		else
		{
			Snake.erase(Snake.begin());
		}


		//3. 방향 전환

		if (!Q.empty())
		{
			int next_time = Q.front().first;
			int next_dir = Q.front().second;

			if (Time == next_time)
			{
				Dir = Change_Dir(Dir, next_dir);
				Q.pop();
			}
		}


		// 4.시간 증가
		Time++;

	}
}