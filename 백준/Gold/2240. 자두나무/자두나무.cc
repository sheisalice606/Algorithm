#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N, T;
int Map[1001];
int dp [31][3][1001];

int main() {

	cin >> N >> T;
	for (int i = 1; i <= N; i++) cin >> Map[i];


	for (int w = 0; w <= T; w++)
	{
		for (int i = 1; i <= N; i++)
		{
			//이동 횟수가 0인 경우
			if (w == 0)
			{
				if (Map[i] == 1) dp[0][1][i] = dp[0][1][i - 1] + 1;
				else if (Map[i] == 2) dp[0][1][i] = dp[0][1][i - 1];
			}
			else
			{
				//현재 자두 위치 : 1
				if (Map[i] == 1)
				{
					//내위치 : 1
					dp[w][1][i] = max(dp[w][1][i - 1], dp[w - 1][2][i - 1]) + 1;
					//내위치 : 2
					dp[w][2][i] = max(dp[w][2][i - 1], dp[w - 1][1][i - 1]);
				}

				//현재 자두 위치 : 2
				if (Map[i] == 2)
				{
					//내위치 : 1
					dp[w][1][i] = max(dp[w][1][i - 1], dp[w - 1][2][i - 1]);
					//내위치 : 2
					dp[w][2][i] = max(dp[w][2][i - 1], dp[w - 1][1][i - 1]) + 1;
				}
			}
		}
	}

	int Ans = -1;
	for (int w = 0; w <= T; w++)
	{
		Ans = max(Ans, dp[w][1][N]);
		Ans = max(Ans, dp[w][2][N]);
	}
	cout << Ans;

}