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
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int N, M, Map[1001][1001], Visit[1001][1001][2];
// [0] = 지팡이 안 씀
// [1] = 지팡이 씀

int Sx, Sy;
int Gx, Gy;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct Data {
	int x;
	int y;
	int time;
	bool used;
};

void Input() {

	cin >> N >> M;
	cin >> Sx >> Sy;
	cin >> Gx >> Gy;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> Map[i][j];
}

int Bfs(int x, int y) {

	queue<Data> Q;
	Q.push({x, y, 0, false});
	Visit[x][y][0] = 1;
	//초기화

	while (!Q.empty())
	{
		int px = Q.front().x;
		int py = Q.front().y;
		int time = Q.front().time;
		bool used = Q.front().used;
		Q.pop();

		//목표 도착
		if (px == Gx && py == Gy)
		{
			return time;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

			
			//지팡이 사용 X
			if (used == false)	
			{
				if (Map[nx][ny] == 1)
				{
					if (Visit[nx][ny][1] == 1) continue;
					Visit[nx][ny][1] = 1;
					Q.push({ nx, ny, time + 1, true });
				}

				if (Map[nx][ny] == 0)
				{
					if (Visit[nx][ny][0] == 1) continue;
					Visit[nx][ny][0] = 1;
					Q.push({ nx, ny, time + 1, false });
				}
			}

			//지팡이 사용 O
			if (used == true)
			{
				if (Map[nx][ny] == 1) continue;
				if (Visit[nx][ny][1] == 1) continue;
				Visit[nx][ny][1] = 1;
				Q.push({ nx, ny, time + 1, true });
			}

		}
		
	}

	//도착 X
	return -1;

}

int main() {
	Input();
	cout << Bfs(Sx, Sy);
}