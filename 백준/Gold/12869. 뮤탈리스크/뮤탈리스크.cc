#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N, Map[3], Visit[3], Mutal[61][61][61];
int Permutation[6][3] =
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

struct SCV {
	int x;
	int y;
	int z;
	int time;
};

int Bfs() {
	queue<SCV> Q;
	Q.push({ Map[0], Map[1], Map[2], 0 });
	Mutal[Map[0]][Map[1]][Map[2]] = 1;

	while (!Q.empty())
	{
		int px = Q.front().x;
		int py = Q.front().y;
		int pz = Q.front().z;
		int time = Q.front().time;
		Q.pop();

		if (px == 0 && py == 0 && pz == 0)
		{
			return time;
		}

		for (int i = 0; i < 6; i++)
		{
			int Gx = Permutation[i][0];
			int Gy = Permutation[i][1];
			int Gz = Permutation[i][2];

			int nx = px - Gx;
			int ny = py - Gy;
			int nz = pz - Gz;

			if (nx < 0) nx = 0;
			if (ny < 0) ny = 0;
			if (nz < 0) nz = 0;

			if (Mutal[nx][ny][nz] == 1) continue;
			Mutal[nx][ny][nz] = 1;
			Q.push({ nx, ny, nz, time + 1 });
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Map[i];
	cout << Bfs();
}