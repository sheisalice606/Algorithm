#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <limits>
#include <stack>
using namespace std;

int T;
char Map[6][10];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> Ans;
//핀의 수, 이동 횟수


void Dfs(int Count, char Curr[6][10]) {

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (Curr[i][j] == 'o') {

				int x = i;
				int y = j;
				//움직일 핀의 위치

				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					int nnx = nx + dx[d];
					int nny = ny + dy[d];

					if (nnx < 1 || nny < 1 || nnx > 5 || nny > 9) continue;
					if (Curr[nx][ny] != 'o' || Curr[nnx][nny] != '.') continue;

			
					char Temp[6][10];
					memcpy(Temp, Curr, sizeof(Temp));

					Temp[x][y] = Temp[nx][ny] = '.';
					Temp[nnx][nny] = 'o';
					Dfs(Count + 1, Temp);

				}

			}
		}
	}

	//더이상 움직일 핀이 없을 떄
	int Cnt = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (Curr[i][j] == 'o') Cnt++;
		}
	}
	Ans.push_back({ Cnt, Count });

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 9; j++) {
				cin >> Map[i][j];
			}
		}
		
		Dfs(0, Map);
		
		sort(Ans.begin(), Ans.end());
		cout << Ans[0].first << ' ' << Ans[0].second << endl;
		Ans.clear();
	}

}
