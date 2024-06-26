#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int N, K, Map[1000000];
vector<int> Ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Map[i];
	}

	int st = 0, en = 0;
	int Cnt = 0;
	while (st <= en) {
		
		if (Cnt == K + 1) {
			Ans.push_back(en - st - (K + 1));
			if (Map[st] % 2 == 1) Cnt--;
			st++;
			continue;
		}

		if (en == N) break;

		if(Cnt <= K) {
			if (Map[en] % 2 == 1) Cnt++;
			en++;
		}

	}

	Ans.push_back(en - st - Cnt);
	sort(Ans.rbegin(), Ans.rend());
	cout << Ans[0];

	//1 3 4 5 6 7 8
}