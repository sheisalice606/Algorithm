#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int T, N, M, Map[21];
int Dp[10001];

void Clear() {
	memset(Map, 0, sizeof(Map));
	memset(Dp, 0, sizeof(Dp));
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> Map[i];
		cin >> M;
		Dp[0] = 1;

		for (int i = 1; i <= N; i++)
		{
			for (int j = Map[i]; j <= M; j++)
			{
				Dp[j] += Dp[j - Map[i]];
			}
		}
		cout << Dp[M] << endl;
		Clear();
	}
}