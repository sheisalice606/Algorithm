#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int N, Ans;
int Dp[100001];

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		Dp[i] = 2e9 + 1;

	for (int i = 1; i <= N; i++)
	{
		int root = sqrt(i);
		for (int j = root; j >= 1; j--)
		{
			Dp[i] = min(Dp[i], Dp[i - (int)pow(j, 2)] + 1);
		}
	}

	cout << Dp[N];
}