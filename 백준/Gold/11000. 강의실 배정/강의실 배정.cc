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

int N;
int Ans = 1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
priority_queue<int, vector<int>, greater<int>> Temp;

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int st, en; 
		cin >> st >> en;
		PQ.push({ st, en });
	}
	//시작 시간 오름차순

	Temp.push(PQ.top().second);
	PQ.pop();
	//첫 원소

	while (!PQ.empty())
	{
		int curr_st = PQ.top().first;
		int curr_en = PQ.top().second;
		PQ.pop();
		//현재 수업 정보

		while (true)
		{
			if (Temp.size() == 0) break;
			if (Temp.top() <= curr_st) Temp.pop();
			else break;
		}

		Temp.push(curr_en);
		Ans = max(Ans, static_cast<int>(Temp.size()));
	}

	cout << Ans;

}