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
int Map[10];
int Ans[10];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> Map[i];

	for (int i = 0; i < N; i++)
	{
		int Curr = i + 1;
		int Cnt = Map[i] + 1;

		for (int j = 0; j < N; j++)
		{
			if (Ans[j] == 0) Cnt--;
			if (Ans[j] > 0) continue;
			if (Cnt == 0) Ans[j] = Curr;
		}

	}

	for (int i = 0; i < N; i++) cout << Ans[i] << ' ';
}