#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N, M;
int Map[101][101];	//불켜진 방	

int Move[101][101]; //아동 가능한 방
int Visit[101][101];


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
map<pair<int, int>, vector<pair<int, int>>> Info;

void Print() {
	cout << "MAP : " << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << ' ';
		} cout << endl;
	} cout << endl;
}

void Bfs() {
	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	Visit[1][1] = 1;

	while (!Q.empty())
	{
		int px = Q.front().first;
		int py = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx > N || ny > N || nx < 1 || ny < 1) continue;
			Move[nx][ny] = 1;
		}
		//현재 기준 인접 칸 표기

		for (int i = 0; i < Info[{px, py}].size(); i++)
		{
			int x = Info[{px, py}][i].first;
			int y = Info[{px, py}][i].second;
			Map[x][y] = 1;
		}
		//불 키기

		for(int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (Visit[i][j] == 1) continue;
				if (Map[i][j] == 1 && Move[i][j] == 1)
				{
					Visit[i][j] = 1;
					Q.push({ i, j });
				}
			}
	}
}

int Make_Ans() {
	int Cnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (Map[i][j] == 1) Cnt++;
	return Cnt;
}

int main() {

	cin >> N >> M;
	Map[1][1] = 1;
	Move[1][1] = 1;
	//초기 상태

	for (int i = 1; i <= M; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		Info[{x, y}].push_back({ a, b });
	}

	Bfs();
	cout << Make_Ans() << '\n';
}