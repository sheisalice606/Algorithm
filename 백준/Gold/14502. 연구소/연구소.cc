#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int Map[9][9];
int Visit[9][9];
int Ans = -1;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<pair<int, int>> Vector; //벽을 세울 수 있는 빈칸의 좌표 모음 : 3개 이상 보장

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 0)
			{
				Vector.push_back({ i, j });
			}
		}
	}
}

void Spread(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue; //범위 초과
		if (Visit[nx][ny] == 1) continue;					//방문 노드(새롭게 퍼진 바이러스 노드)
		if (Map[nx][ny] == 1 || Map[nx][ny] == 2) continue; //벽 or 기존 바이러스

		//cout << "새로운 칸 전염" << endl;
		Visit[nx][ny] = 1; 
		Spread(nx, ny);
	}
}


int Make_Ans() {
	int Cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == 0 && Visit[i][j] == 0) Cnt++;		//빈 칸
		}
	}
	return Cnt;
}

void Clear() {
	memset(Visit, 0, sizeof(Visit));
}

void Dfs(int Count, int Index) {

	if (Count == 3)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (Map[i][j] == 2 && Visit[i][j] == 0)
				{
					Visit[i][j] = 1;
					Spread(i, j);
				}
			}
		}

		int Curr = Make_Ans();
		Ans = max(Ans, Curr);
		//cout << "남은 칸 : " << Curr << endl;
		Clear();
		return;
	}

	for (int n = Index; n < Vector.size(); n++)
	{
		int px = Vector[n].first;
		int py = Vector[n].second;
		
		Map[px][py] = 1;
		Dfs(Count + 1, n + 1);
		Map[px][py] = 0;
	}

}

int main() {
	Input();
	Dfs(0, 0);
	cout << Ans << '\n';
}