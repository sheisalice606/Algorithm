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

int N;
int Map[500000];
int Ans[500000];
stack<pair<int, int>> Stack;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];

	Ans[0] = 0;
	Stack.push({ 1, Map[0] });
	for (int i = 1; i < N; i++)
	{
		int curr = Map[i];

		//스택을 모두 제거 or Curr 이상의 기둥 발견시 멈춤
		while (Stack.size() > 0 && Stack.top().second < curr) Stack.pop();

		if (Stack.size() == 0)
		{
			Ans[i] = 0;
			Stack.push({ i + 1, curr });
			continue;
		}
		else
		{
			Ans[i] = Stack.top().first;
			Stack.push({ i + 1, curr });
			continue;
		}
	}

	for (int i = 0; i < N; i++) cout << Ans[i] << ' ';
} 