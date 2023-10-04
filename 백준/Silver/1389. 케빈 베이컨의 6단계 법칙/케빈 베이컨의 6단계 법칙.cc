#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int N, M;
int Dist[101][101];

//Index, Sum
bool Cmp(pair<int, int>& A, pair<int, int>& B) {
	if (A.second == B.second) return A.first < B.first;
	else return A.second < B.second;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			Dist[i][j] = 987654321;

	for (int i = 1; i <= N; i++)
		Dist[i][i] = 0;
	//모든 유저끼리의 거리 : INF

	for (int i = 1; i <= M; i++)
	{
		int A, B;
		cin >> A >> B;
		Dist[A][B] = 1;
		Dist[B][A] = 1;
	}
	//정보 바탕 초기화

	for (int n = 1; n <= N; n++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (Dist[i][j] > Dist[i][n] + Dist[n][j])
					Dist[i][j] = Dist[i][n] + Dist[n][j];

	vector<pair<int, int>> Ans;
	for (int i = 1; i <= N; i++)
	{
		int Sum = 0;
		for (int j = 1; j <= N; j++)
			Sum += Dist[i][j];
		Ans.push_back({ i, Sum });
	}
	sort(Ans.begin(), Ans.end(), Cmp);
	cout << Ans[0].first;
} 