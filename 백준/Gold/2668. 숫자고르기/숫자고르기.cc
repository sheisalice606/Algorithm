#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <limits>
#include <stack>
using namespace std;

int N, Map[101], Visit[101];

bool Flag = false;
vector<int> Temp, Ans;

void Dfs(int curr, int start, int count) {

	int next = Map[curr];

	if (next == start && count > 0) {
		Flag = true;
		return;
	}

	if (Visit[next] == 0) {
		Visit[next] = 1;
		Temp.push_back(next);
		Dfs(next, start, count + 1);
		Visit[next] = 0;
	}

}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Map[i];
		if (i == Map[i]) {
			Visit[i] = 1;
			Ans.push_back(i);
		}
	}
	//입력

	for (int i = 1; i <= N; i++) {
		if (Visit[i] == 1) continue;

		Visit[i] = 1;
		Temp.push_back(i);
		Dfs(i, i, 0);
		Visit[i] = 0;

		if (Flag == true) {
			for (int n : Temp) {
				Ans.push_back(n);
				Visit[n] = 1;
			}
		}

		Temp.clear();
		Flag = false;
	}
	//사이클 탐색 사이클이 2개 이상일 수 있다.
	//사이클이 확정된 요소는 영구 방문처리하고, Ans에 삽입한다.

	sort(Ans.begin(), Ans.end());
	cout << Ans.size() << endl;
	for (int n : Ans) cout << n << endl;

}