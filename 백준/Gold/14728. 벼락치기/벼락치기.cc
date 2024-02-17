#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

pair<int, int> Map[101];
int N, T, Dp[101][10001];


int main() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
		cin >> Map[i].first >> Map[i].second;

	//과목의 수
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			//j는 현재 고려하는 최대 무게인데, j보다 커서 i번째 물건을 아예 못넣는 경우다.
			if (Map[i].first > j) Dp[i][j] = Dp[i - 1][j];
			else Dp[i][j] = max(Dp[i - 1][j], Dp[i - 1][j - Map[i].first] + Map[i].second);
			//어떻게든 넣을 수 있다면, 현재값과 i번째 물건을 넣은경우 중 큰 값을 저장한다.
		}
	}

	cout << Dp[N][T];
}