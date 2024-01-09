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
#include <sstream>
#include <deque>
using namespace std;

int N;
int Map[33][33];
long long Dp[33][33][3];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];
}

void Solve() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (k == 0)
				{
					if (Map[i][j + 1] == 0) Dp[i][j + 1][0] += Dp[i][j][0];
					if (Map[i + 1][j + 1] == 0 && Map[i + 1][j] == 0 && Map[i][j + 1] == 0) Dp[i + 1][j + 1][1] += Dp[i][j][0];
				}

				if (k == 1)
				{
					if (Map[i][j + 1] == 0) Dp[i][j + 1][0] += Dp[i][j][1];
					if (Map[i + 1][j + 1] == 0 && Map[i + 1][j] == 0 && Map[i][j + 1] == 0) Dp[i + 1][j + 1][1] += Dp[i][j][1];
					if (Map[i + 1][j] == 0) Dp[i + 1][j][2] += Dp[i][j][1];
				}

				if (k == 2)
				{
					if (Map[i + 1][j + 1] == 0 && Map[i + 1][j] == 0 && Map[i][j + 1] == 0) Dp[i + 1][j + 1][1] += Dp[i][j][2];
					if (Map[i + 1][j] == 0) Dp[i + 1][j][2] += Dp[i][j][2];
				}
			}
		}
	}
}

int main() {

	Dp[1][2][0] = 1;
	Dp[1][2][1] = 0;
	Dp[1][2][2] = 0;
	Input();
	Solve();
	cout << Dp[N][N][0] + Dp[N][N][1] + Dp[N][N][2];

}