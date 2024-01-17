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

int T;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

char Map[6][10];
vector<pair<int, int>> Ans;
//좌표 and 삭제 여부


int Make_Ans() {
	int Cnt = 0;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 9; j++)
			if (Map[i][j] == 'o')
				Cnt++;
	return Cnt;
}

bool Cmp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first)
		return A.second < B.second;
	return A.first < B.first;
}


void Dfs(int Count) {

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (Map[i][j] == 'o')
			{
				for (int d = 0; d < 4; d++)
				{
					int nx = i + dx[d];
					int ny = j + dy[d];

					int nnx = nx + dx[d];
					int nny = ny + dy[d];

					if (nx < 1 || ny < 1 || nx > 5 || ny > 9) continue;
					if (Map[nx][ny] != 'o') continue;


					if (nnx < 1 || nny < 1 || nnx > 5 || nny > 9) continue;
					if (Map[nnx][nny] != '.') continue;
					

					Map[i][j] = '.';							
					Map[nx][ny] = '.';						
					Map[nnx][nny] = 'o';	

					Dfs(Count + 1);

					Map[i][j] = 'o';
					Map[nx][ny] = 'o';
					Map[nnx][nny] = '.';

				}
			}
		}

	Ans.push_back({ Make_Ans(), Count });
	return;

}

int main() {

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		for (int i = 1; i <= 5; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < 9; j++)
				Map[i][j + 1] = str[j];
		}
		//초기화

		Dfs(0);
		sort(Ans.begin(), Ans.end(), Cmp);
		cout << Ans[0].first << ' ' << Ans[0].second << endl;
		//출력

		Ans.clear();
		//리셋
	}


}