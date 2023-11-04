#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N, K;
int Ans = 0;

int Map[200000];
int Arr[100001];

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}
	//초기화

	int Cnt = 0;
	int st = 0;
	for (int en = 0; en < N; en++)
	{
		int curr = Map[en];
		Arr[curr]++;

		//임계치 미만
		if (Arr[curr] <= K)
		{
			Cnt++;
			continue;
		}
		else
		{
			Cnt++;
			Ans = max(Ans, Cnt - 1);

			while (Arr[curr] > K && st < en)
			{
				int e = Map[st];
				Arr[e]--;
				st++;
				Cnt--;
			}
		}
	}

	Ans = max(Ans, Cnt);
	cout << Ans << endl;
}