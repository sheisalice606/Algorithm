#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int T, N;
int map[100001];
int visit[100001];
int check[100001];

int member = 0;


void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
}

void clear() {

	member = 0;
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	memset(check, 0, sizeof(check));

}


void dfs(int start) {
	
	int next = map[start];

	if (visit[next] == 0) {
		visit[next] = 1;
		dfs(next);
	}
	else if (check[next] == 0) { // 이미 방문은 하였으나, 사이클 여부 확인이 안된 경우

		for (int i = next; i != start; i = map[i]) {
			member++; // 본인 제외 사이클 멤버 수 카운트
		}
		member++; // 본인 카운트

	}

	check[start] = 1;

}


int main() {

	cin >> T;

	while (T > 0) {

		input();

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				dfs(i);
			}
		}

		cout << N - member << '\n';

		clear();
		T--;
	}

	return 0;

}