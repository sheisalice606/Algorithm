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
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int N, M, Origin;
int Score[200000], Unit[200000];
priority_queue<pair<int, int>> PQ;
// Left , Cnt

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Score[i];
		Origin += Score[i];
	}
	for (int i = 0; i < M; i++) cin >> Unit[i];
}

int Solve() {

	int Time = 24 * N;
	int Total = 0;
	while (true)
	{
		if (PQ.empty() == true) break;

		int Unit = PQ.top().first;
		int Cnt = PQ.top().second;
		PQ.pop();

		while (Cnt--)
		{
			Total += Unit;
			Time--;
			if (Time == 0) return Total;
		}

	}
	return Total;
}

int main() {
	Input();
	for (int i = 0; i < M; i++)
	{
		int Cnt = 100 - Score[i]; // 100점까지 남은 점수
		
		if (Cnt < Unit[i])
		{
			PQ.push({ Cnt, 1 });
			continue;
		}

		if (Cnt % Unit[i] == 0)
		{
			PQ.push({ Unit[i], Cnt / Unit[i]});
			continue;
		}

		int Left = Cnt % Unit[i];
		PQ.push({ Unit[i], Cnt / Unit[i]});
		PQ.push({ Left, 1 });

	}
	cout << Origin + Solve();
}