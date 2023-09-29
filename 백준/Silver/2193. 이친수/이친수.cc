#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

long long dp[100][2];

int main() {

	int N;
	cin >> N;

	dp[1][0] = 0;
	dp[1][1] = 1;

	dp[2][0] = dp[1][1];
	dp[2][1] = dp[1][0];

	for (int i = 3; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1];

}