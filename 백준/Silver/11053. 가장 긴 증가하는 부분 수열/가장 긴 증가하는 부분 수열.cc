#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int Map[1001];
int dp[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> Map[i];
	for (int i = 1; i <= N; i++) dp[i] = 1;

	for (int i = 1; i <= N; i++)
	{
		//dp[i]는 i번째 원소를 마지막으로 가지는 수열
		for (int j = 1; j < i; j++)
		{
			if (Map[i] > Map[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int Ans = -1;
	for (int i = 1; i <= N; i++) Ans = max(Ans, dp[i]);
	cout << Ans;

} 