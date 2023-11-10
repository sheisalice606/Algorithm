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

int N, M;
priority_queue<long long, vector<long long>, greater<long long>> PQ;

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		long long n; 
		cin >> n;
		PQ.push(n);
	}

	for (int i = 0; i < M; i++)
	{
		long long First = PQ.top();
		PQ.pop();

		long long Second = PQ.top();
		PQ.pop();

		PQ.push(First + Second);
		PQ.push(First + Second);
	}

	long long Ans = 0;
	while (!PQ.empty())
	{
		Ans += PQ.top();
		PQ.pop();
	}
	cout << Ans;
}