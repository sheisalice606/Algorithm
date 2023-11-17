#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
using namespace std;

int N, Map[100001];
map<int, int> M;
long long Ans;

int Make(int N) {
	int Sum = 0;
	for (int i = 1; i <= N; i++)
		Sum += i;
	return Sum;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Map[i];
	//Input

	// 1 2 3 1 1 4

	int st = 1;
	for (int en = 1; en <= N; en++)
	{
		int curr = Map[en];
		M[curr]++;

		if (M[curr] == 2)
		{
			while (M[curr] != 1 && st <= en)
			{
				M[Map[st]]--;
				st++;
			}

			Ans += (en - st + 1);
			continue;
		}

		Ans += (en - st + 1);
	}

	cout << Ans << '\n';
}