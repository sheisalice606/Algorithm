#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;
#define INF 987654321

int N, S;
int cnt = 0;
int sum = 0;
int map[21];
int visit[21];
// 백트래킹

void dfs(int count, int index) {

	if (count > N) {
		return;
	}


	for (int i = index; i <= N; i++) {

		if (!visit[i]) {
			visit[i] = 1;
			sum += map[i];
			if (sum == S) {
				cnt++;
			}
			
			dfs(count + 1, i + 1);

			// 원소 하나 제거
			visit[i] = 0;
			sum -= map[i];
		}

	}


}


int main() {

	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}

	dfs(1, 1);
	cout << cnt;

}