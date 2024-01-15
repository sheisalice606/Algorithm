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

int N;
int Map[100001], Cnt[100001], Near[100001];
stack<pair<int, int>> Stack, Stack_2;
// Num, Index

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Map[i];
	//Input()

	for (int i = 1; i <= N; i++)
	{
		while (!Stack.empty() && Stack.top().first <= Map[i]) Stack.pop();
		Cnt[i] += Stack.size();
		//cout << "CURR CNT : " << Cnt[i] << endl;
		if (!Stack.empty() && Near[i] == 0) Near[i] = Stack.top().second;
		Stack.push({ Map[i], i });
	}
	// 정방향 순회

	for (int i = N; i >= 1; i--)
	{ 
		while (!Stack_2.empty() && Stack_2.top().first <= Map[i]) Stack_2.pop();
		Cnt[i] += Stack_2.size();
		if (!Stack_2.empty())
		{
			if (Near[i] == 0)
				Near[i] = Stack_2.top().second;
			else if (abs(i - Near[i]) > abs(i - Stack_2.top().second)) 
				Near[i] = Stack_2.top().second;
				//기존 Near[i] VS Stack.top().second
		}
		Stack_2.push({ Map[i], i });
	}
	// 역방향 순회

	for (int i = 1; i <= N; i++)
	{
		if (Cnt[i] == 0)
			cout << 0 << '\n';
		else
			cout << Cnt[i] << ' ' << Near[i] << '\n';
	}

}