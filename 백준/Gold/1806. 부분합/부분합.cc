#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int N, K, Ans = 1e9;
int Map[100000];

void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> Map[i];
}

int main() {
	Input();
	
	int st = 0;
	int en = 0;
	int Sum = 0;
	while (st <= en && en <= N)
	{
		if (Sum >= K)
		{
			Ans = min(Ans, en - st);
		}

		if(Sum < K)
		{
			Sum += Map[en];
			en++;
		}
		else
		{
			Sum -= Map[st];
			st++;
		}

	}

	if (Ans == 1e9) cout << 0;
	else cout << Ans;

}