#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
#include <cmath>
using namespace std;

int T, A, B;
int Min, Ans = -1;
int Visit[5000001];

int Bfs() {
	queue<pair<int, int>> Q;
	Q.push({0, 0});
	Visit[0] = 1;

	while (!Q.empty())
	{
		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		Ans = max(Ans, curr);

		int case_A = curr + A;
		if (case_A <= T && Visit[case_A] == 0)
		{
			Visit[case_A] = 1;
			Q.push({ case_A, time });
		}

		int case_B = curr + B;
		if (case_B <= T && Visit[case_B] == 0)
		{
			Visit[case_B] = 1;
			Q.push({ case_B, time });
		}

		int case_water = curr / 2;
		if (time == 0 && Visit[case_water] == 0)
		{
			Visit[case_water] = 1;
			Q.push({ case_water, 1 });
		}
	}

	return Ans;
}

int main() {
	cin >> T >> A >> B;
	cout << Bfs();
}