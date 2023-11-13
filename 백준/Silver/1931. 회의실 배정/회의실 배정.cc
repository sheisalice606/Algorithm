#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int Cnt = 0;


int main() {

	cin >> N;
	vector<pair<int, int>> Vector(N);
	for (int i = 0; i < N; i++) {
		cin >> Vector[i].second >> Vector[i].first;
		//first = 회의 종료 시간, second = 회의 시작 시간
	}

	sort(Vector.begin(), Vector.end());
	int Component = 0;
	for (int i = 0; i < N; i++) {
		if (Component <= Vector[i].second) {
			//회의가 빨리 끝나는 순에서 현재 시작이 가능한 회의
			Component = Vector[i].first;

			//cout << Vector[i].second << ' ' << Vector[i].first << endl;
			Cnt++;
		}
	}
	cout << Cnt;
}