#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int T, N;
int mx, my;
int gx, gy;

struct Store {
	int id;
	int x;
	int y;
};

vector<Store> Vector;
int Visit[101][101];

void Input() {
	cin >> T;
}

void Clear() {
	Vector.clear();
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			Visit[i][j] = 0;
		}
	}
}

void Bfs() {

	queue<pair<pair<int, int>, int>> Q;
	Q.push({ {mx, my}, 0 });
	//원점 = 0, 편의점 = 1 - 100

	while (!Q.empty())
	{
		int px = Q.front().first.first;
		int py = Q.front().first.second;
		int pid = Q.front().second;
		Q.pop();

		if (abs(px - gx) + abs(py - gy) <= 1000)
		{
			cout << "happy" << '\n';
			return;
		}

		for (int i = 0; i < Vector.size(); i++)
		{
			int nid = Vector[i].id;
			int nx = Vector[i].x;
			int ny = Vector[i].y;

			if (abs(px - nx) + abs(py - ny) > 1000) continue;
			if (Visit[pid][nid] == 1) continue;

			Visit[pid][nid] = 1;
			Q.push({ {nx, ny}, nid });
		}
		
	}

	cout << "sad" << '\n';
	return;

}

int main()
{
	Input();
	while (T--)
	{
		cin >> N;
		cin >> mx >> my;
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			Vector.push_back({ i + 1, x, y });
			// id : 1 - 100
		}

		cin >> gx >> gy;
		Bfs();
		Clear();
	}
}