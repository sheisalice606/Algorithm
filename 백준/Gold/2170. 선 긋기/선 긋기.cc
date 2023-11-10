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
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int st, en;
		cin >> st >> en;
		PQ.push({ st, en });
	}
	//기본 세팅

	int st = PQ.top().first;
	int en = PQ.top().second;
	Ans += (en - st);
	PQ.pop();

	while (!PQ.empty())
	{
		int curr_st = PQ.top().first;
		int curr_en = PQ.top().second;
		PQ.pop();

		if (curr_st >= en)
		{
			st = curr_st;
			en = curr_en;
			Ans += (en - st);
			continue;
		}
		else
		{
			if (curr_en > en)
			{
				Ans += (curr_en - en);
				en = curr_en;
			}
		}
	}

	cout << Ans;

}