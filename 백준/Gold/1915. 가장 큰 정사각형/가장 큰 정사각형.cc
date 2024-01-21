#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int N, M;
int Dp[1001][1001];
char Map[1001][1001];

void Input() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Map[i][j];
		}
	}
}

int main() {

	Input();

	int Ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (Map[i][j] == '0')
			{
				Dp[i][j] = 0;
			}
			else
			{
				Dp[i][j] = min({ Dp[i - 1][j], Dp[i][j - 1], Dp[i - 1][j - 1] }) + 1;
				Ans = max(Ans, Dp[i][j]);
			}
			
		}

	cout << Ans * Ans;
}