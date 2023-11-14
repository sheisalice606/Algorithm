#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

int Ans = 0;
int Visit[25];
char Map[5][5];


vector<pair<int, int>> Temp;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };



bool Check_Cnt() {
	int Cnt = 0;
	for (auto E : Temp)
	{
		if (Map[E.first][E.second] == 'S') Cnt++;
	} 
	return Cnt >= 4;
}

bool Check_Dist() {

	int arr[5][5] = { 0 };
	int Check[5][5] = { 0 };
	for (int i = 0; i < Temp.size(); i++)
		arr[Temp[i].first][Temp[i].second] = 1;
	//임시 배열 생성


	queue<pair<int, int>> Q;
	Q.push({Temp[0].first, Temp[0].second});
	Check[Temp[0].first][Temp[0].second] = 1;
	//임시 Queue 생성


	while (!Q.empty())
	{
		int px = Q.front().first;
		int py = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (arr[nx][ny] == 0) continue;
			if (Check[nx][ny] == 1) continue;

			Check[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arr[i][j] == 1 && Check[i][j] == 0)
				return false;

	return true;
}

void Dfs(int Count, int Idx) {

	if (Count == 7)
	{
		if (Check_Cnt() == true)
			if (Check_Dist() == true)
				Ans++;
		return;
	}

	for (int i = Idx; i < 25; i++)
	{
		Temp.push_back({ i / 5, i % 5 });
		Dfs(Count + 1, i + 1);
		Temp.pop_back();
	}

}

int main() {

	for (int i = 0; i < 5; i++)
	{
		string S; cin >> S;
		for (int j = 0; j < 5; j++)
		{
			Map[i][j] = S[j];
		}
	}
	//입력

	Dfs(0, 0);
	//탐색

	cout << Ans;
	//출력
}