#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <limits>
#include <stack>
using namespace std;

int N;
vector<int> Ans;

int main() {
	cin >> N;

	int st = 1, en = 1;
	while (true) {

		int curr = pow(en, 2) - pow(st, 2);

		if (curr == N) {
			Ans.push_back(en);
		}

		if (en - st == 1 && curr > N) break;

		if (curr > N) st++;
		else en++;

	}

	if (Ans.size() == 0) cout << -1;
	else {
		for (int n : Ans) cout << n << endl;
	}
	
}