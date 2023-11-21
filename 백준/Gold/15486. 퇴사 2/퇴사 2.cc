#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int N;
int P[1500001];
int T[1500001];
int DP[1500001];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; i--)
	{
		int Fin = i + T[i];

		if (Fin > N + 1)
			DP[i] = DP[i + 1];
		else
			DP[i] = max(DP[i + 1], DP[Fin] + P[i]);
		
	}

	cout << DP[1];
}