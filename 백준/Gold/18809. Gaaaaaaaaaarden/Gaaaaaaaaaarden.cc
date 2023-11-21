#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int N, M;
int R, G;
int Map[51][51];
//0 : 호수 
//1 : 배양액 X 
//2 : 배양액 O



pair<int, int> Color[51][51]; 
// F : 레드 S : 그린
int Visit[51][51];


int Flower;
int Ans;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


vector<pair<int, int>> Land;
vector<pair<int, int>> Temp;
vector<pair<int, int>> Red;


void Spread_Clear() {

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			Color[i][j] = { 0,0 };

	memset(Visit, 0, sizeof(Visit));
	Flower = 0;
}


void Spread() {


	queue<pair<pair<int, int>, int>> Q;

	//R 색칠
	for (int i = 0; i < Red.size(); i++)
	{
		int px = Red[i].first;
		int py = Red[i].second;
		Color[px][py].first = 1;
		Visit[px][py] = 1;
		Q.push({ {px, py}, 0 });
	}

	//G 색칠
	for (int i = 0; i < Temp.size(); i++)
	{
		int px = Temp[i].first;
		int py = Temp[i].second;

		if (Color[px][py].first == 0)
		{
			Color[px][py].second = 1;
			Visit[px][py] = 1;
			Q.push({ {px, py}, 0 });
		}
	}


	map<pair<int, int>, int> Temp;
	//Visit 처리용도


	while(!Q.empty())
	{

		int px = Q.front().first.first;
		int py = Q.front().first.second;
		int Time = Q.front().second;
		Q.pop();



		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;	//범위 이탈
			if (Visit[nx][ny] == 1) continue;					//방문 처리
			if (Map[nx][ny] == 0) continue;						//호수

			

			if (Color[px][py].first > 0 && Color[px][py].second == 0)
			{
				Color[nx][ny].first++;
			}
			else if (Color[px][py].second > 0 && Color[px][py].first == 0)
			{
				Color[nx][ny].second++;
			}

			Temp[{nx, ny}]++;
		}
		

		//Temp에 포함된 좌표는 모두 동시에 번짐
		if (Q.size() == 0)
		{
			for (auto E : Temp)
			{
				int x = E.first.first;
				int y = E.first.second;

				Visit[x][y] = 1;

				if (Color[x][y].first > 0 && Color[x][y].second > 0)
				{
					Flower++;
					continue;
				}

				Q.push({ {x, y}, Time + 1 });
			}

			Temp.clear();
		}

	}

	return;
}


//색 조합
void Dfs_2(int Count, int Idx) {

	//나머지는 G
	if (Count == R)
	{
		Spread();
		Ans = max(Ans, Flower);
		Spread_Clear();
		return;
	}

	for (int i = Idx; i < Temp.size(); i++)
	{
		Red.push_back({ Temp[i].first, Temp[i].second });
		Dfs_2(Count + 1, i + 1);
		Red.pop_back();
	}
}


//땅을 정하는 백트래킹
void Dfs(int Count, int Idx) {

	if (Count == R + G)
	{
		Dfs_2(0, 0);
		Red.clear();
		return;
	}

	for (int i = Idx; i < Land.size(); i++)
	{
		Temp.push_back({ Land[i].first, Land[i].second });
		Dfs(Count + 1, i + 1);
		Temp.pop_back();
	}

}


void Input() {
	cin >> N >> M >> G >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2)
			{
				Land.push_back({ i,j });
				//배양액 뿌리는 땅
			}
		}


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			Color[i][j] = { 0,0 };
	//초기화
}

int main() {

	Input();
	Dfs(0, 0);
	cout << Ans;

}