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

int T, N;
long long Ans;
int Map[1000001];

void Clear() { 
	N = 0;
	Ans = 0;
	memset(Map, 0, sizeof(Map));
}

int main() {

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> Map[i];
		}

		int Top = -1;
		for (int i = N; i >= 1; i--)
		{
			if (Map[i] > Top)
			{
				Top = Map[i];
				continue;
			}

			Ans += (Top - Map[i]);
		}

		cout << Ans << '\n';
		Clear();
	}
}