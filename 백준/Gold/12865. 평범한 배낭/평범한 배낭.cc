#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int N, M;
pair<int, int> Map[101];
int Dp[101][100001];
//최대이익[i][w] = 최대무게가 w인 가방에서 i번째 물건까지 판단했을 때의 최대 가치

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int W, P;
		cin >> W >> P;
		Map[i] = { W,P };
	}
}

int main() {

	Input();

	for (int i = 1; i <= N; i++)
	{
		int W = Map[i].first;
		int P = Map[i].second;

		for (int j = 1; j <= M; j++)
		{
			if (W > j)
				Dp[i][j] = Dp[i - 1][j];
			else
				Dp[i][j] = max(Dp[i - 1][j], P + Dp[i - 1][j - W]);
		}
	}

	cout << Dp[N][M];

}