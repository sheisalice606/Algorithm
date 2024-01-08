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
int Map[201];
int Dp[201];

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Map[i];
	}

	int Max = -1;
	for (int i = 1; i <= N; i++)
	{
		Dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (Map[i] > Map[j])
			{
				Dp[i] = max(Dp[i], Dp[j] + 1);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		Max = max(Max, Dp[i]);
	}
	cout << N - Max;
}