#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

long long dp[1000001];

int main() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int i = 5; i <= 1000000; i++)
	{
		dp[i] = ( dp[i - 1] + dp[i - 2] + dp[i - 3] ) % 1000000009;
	}
	
	int N;
	cin >> N;
	while (N--)
	{
		int n; cin >> n;
		cout << dp[n] << endl;
	}
}