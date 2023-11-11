#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;

//검은색 -1
//무지개 0

//그룹 : 일반 블록 하나 이상 포함, 검은 블록 X, 무지개는 제한 없음 -> 총 크기 2 이상
//그룹의 기존 블록 : 무지개 블록 X, 행이 작은 블록 -> 열이 작은 블록

int N, M, Ans;
int Map[21][21];
int Visit[21][21];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct Group {
	int X;
	int Y;

	vector<pair<int, int>> Position;	//일반 블록
	vector<pair<int, int>> Rainbow;		//무지개 블록
};

vector<Group> Vector;

void Print() {
	for (auto E : Vector)
	{
		cout << "그룹 크기 : " << E.Position.size() + E.Rainbow.size() << '\n';
		cout << "무지개 블록의 수 : " << E.Rainbow.size() << '\n';
		for (auto E2 : E.Position)
		{
			cout << "일반 블록 좌표 : " << E2.first << " , " << E2.second << '\n';
		}
		for (auto E2 : E.Rainbow)
		{
			cout << "무지개 블록 좌표 : " << E2.first << " , " << E2.second << '\n';
		}
		cout << endl;
	}
}

void Print_Map() {
	cout << "MAP : " << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << "   ";
		}
		cout << endl;
	} cout << endl;
}

//가장 큰 그룹 정하기
bool Cmp(Group A, Group B) {
	if (A.Position.size() + A.Rainbow.size() == B.Position.size() + B.Rainbow.size())
	{
		if (A.Rainbow.size() == B.Rainbow.size())
		{
			if (A.X == B.X)
			{
				return A.Y > B.Y;
			}
			return A.X > B.X;
		}
		return A.Rainbow.size() > B.Rainbow.size();
	}
	return A.Position.size() + A.Rainbow.size() > B.Position.size() + B.Rainbow.size();
}

//기준 블록 정하기
bool Cmp2(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first)
	{
		return A.second < B.second;
	}
	return A.first < B.first;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];
}

void Dfs(int x, int y, int L, Group& G) {
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
		if (Visit[nx][ny] == 1) continue;	//방문한 일반 블록
		if (Map[nx][ny] < 0) continue;		//검은 블록 or 빈칸
		if (Map[nx][ny] > 0 && Map[nx][ny] != L) continue;		//그룹 범위 X

		Visit[nx][ny] = 1;

		if (Map[nx][ny] == 0)
		{
			G.Rainbow.push_back({ nx, ny });
			Dfs(nx, ny, L, G);
		}
		else if (Map[nx][ny] == L)
		{
			G.Position.push_back({ nx, ny });
			Dfs(nx, ny, L, G);
		}
		
	}
}

void Label() {
	
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (Visit[i][j] == 1) continue;
			if (Map[i][j] <= 0) continue;

			Visit[i][j] = 1;
			Group G;
			G.Position.push_back({ i, j });

			Dfs(i, j, Map[i][j], G);
			
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					if (Map[i][j] == 0) Visit[i][j] = 0;

			//그룹의 전체 크기 2 이상 + 하나 이상의 일반 블록 포함
			if ((G.Position.size() + G.Rainbow.size()) >= 2 && G.Position.size() > 0)
			{
				Vector.push_back(G);
			}

		}
}

//중력 작용
void Gravity() {

	//각 열마다 작용
	for (int i = 1; i <= N; i++)
	{
		//마지막 행은 해당 X
		for (int j = N - 1; j >= 1; j--)
		{
			if (Map[j][i] < 0) continue;
			
			int px = j;
			int py = i;

			while (Map[px + 1][py] == -999)
			{
				Map[px + 1][py] = Map[px][py];
				Map[px][py] = -999;
				px += 1;

				if (px + 1 > N) break;
			}
		}
	}
}

void Rotation() {
	int Temp[21][21] = { 0 };
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			Temp[N - j + 1][i] = Map[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			Map[i][j] = Temp[i][j];
}

int main() {

	Input();

	while (true)
	{

		Label();
		memset(Visit, 0, sizeof(Visit));
		// 그룹 선별

		if (Vector.size() == 0) break;


		for (auto& E : Vector)
		{
			sort(E.Position.begin(), E.Position.end(), Cmp2);
			E.X = E.Position[0].first;
			E.Y = E.Position[0].second;
		}
		//기준 블록 정함

		sort(Vector.begin(), Vector.end(), Cmp);
		//가장 큰 그룹 정함

		Ans += (Vector[0].Position.size() + Vector[0].Rainbow.size()) * (Vector[0].Position.size() + Vector[0].Rainbow.size());
		//점수 합산

		for (int i = 0; i < Vector[0].Position.size(); i++)
		{
			int x = Vector[0].Position[i].first;
			int y = Vector[0].Position[i].second;
			Map[x][y] = -999;
		}

		for (int i = 0; i < Vector[0].Rainbow.size(); i++)
		{
			int x = Vector[0].Rainbow[i].first;
			int y = Vector[0].Rainbow[i].second;
			Map[x][y] = -999;
		}
		//원소 삭제

		Vector.clear();
		//그룹 완전 초기화

		Gravity();
		//중력 작용

		Rotation();
		//반시계 90도 회전

		Gravity();
		//중력 작용
	}


	cout << Ans;
	
	
}