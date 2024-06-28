#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <stack>
#include <string>
using namespace std;

int N, M, Parent[201], Dist[201][201], Map[1001];
//결국 서로소인 집합의 정보를 구해야한다.


void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

int Find(int x) {
	if (x == Parent[x]) return x;
	return Find(Parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	
	if (a == b) return;
	if (a < b) Parent[a] = b;
	else Parent[b] = a;
}

int main() {

	cin >> N >> M;
	Init();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Dist[i][j];
			if (Dist[i][j] == 1) {
				Union(i, j);
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> Map[i];
	}

	for (int i = 1; i < M; i++) {
		if (Find(Map[i]) != Find(Map[i + 1])) {
			cout << "NO" << endl;
			exit(0);
		}
	}
	cout << "YES" << endl;

}