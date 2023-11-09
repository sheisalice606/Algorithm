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

int N, Ans;
vector<int> P;
vector<int> M;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		if (n > 0) P.push_back(n);
		else M.push_back(n);
	}
	sort(P.begin(), P.end());
	sort(M.begin(), M.end());
	//오름차순 정렬

	if (M.size() % 2 == 0)
	{
		for (int i = 0; i < M.size(); i += 2)
		{
			Ans += (M[i] * M[i + 1]);
		}
	}
	else
	{
		for (int i = 0; i < M.size() - 1; i += 2)
		{
			Ans += (M[i] * M[i + 1]);
		}
		Ans += M[M.size() - 1];
	}


	if (P.size() % 2 == 0)
	{
		for (int i = 0; i < P.size(); i += 2)
		{
			Ans += max(P[i] + P[i + 1], P[i] * P[i + 1]);
		}
	}
	else
	{
		for (int i = P.size() - 1; i > 0; i -= 2)
		{
			Ans += max(P[i] + P[i - 1], P[i] * P[i - 1]);
		}
		Ans += P[0];
	}

	cout << Ans << '\n';
}