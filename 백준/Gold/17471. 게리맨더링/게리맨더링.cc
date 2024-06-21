#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int N, Visit[11], Person[11], Ans = 1e9;
vector<int> Node[11];
vector<int> TeamA, TeamB;


bool Check_TeamA() {

	queue<int> Q;
	int Temp[11] = { 0 };
	Q.push(TeamA[0]);
	Temp[TeamA[0]] = 1;
	//삽입과 방문처리

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		for (int i = 0; i < Node[curr].size(); i++) {
			int next = Node[curr][i];
			if (Temp[next] == 1) continue;
			if (Visit[next] == 0) continue;
			//B팀에 속한 노드인 경우 전진불가

			Temp[next] = 1;
			Q.push(next);
		}
	}
	//모든 연결처리
	
	for (int i = 0; i < TeamA.size(); i++) {
		if (Temp[TeamA[i]] == 0) return false;
	}
	return true;
}

bool Check_TeamB() {

	queue<int> Q;
	int Temp[11] = { 0 };
	Q.push(TeamB[0]);
	Temp[TeamB[0]] = 1;
	//삽입과 방문처리

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		for (int i = 0; i < Node[curr].size(); i++) {
			int next = Node[curr][i];
			if (Temp[next] == 1) continue;
			if (Visit[next] == 1) continue;
			//A팀에 속한 노드인 경우 전진불가

			Temp[next] = 1;
			Q.push(next);
		}
	}
	//모든 연결처리

	for (int i = 0; i < TeamB.size(); i++) {
		if (Temp[TeamB[i]] == 0) return false;
	}
	return true;
}

int Make_Ans() {
	int sum_A = 0, sum_B = 0;
	for (int n : TeamA) sum_A += Person[n];
	for (int n : TeamB) sum_B += Person[n];
	return abs(sum_A - sum_B);
}

void Make_TeamB() {
	for (int i = 1; i <= N; i++) {
		if (Visit[i] == 0) TeamB.push_back(i);
	}
}

void Dfs(int Count, int Idx, int G) {
	//팀 구성이 완료된 경우
	if (Count == G) {
		Make_TeamB();
		if (Check_TeamA() && Check_TeamB()) {
			Ans = min(Ans, Make_Ans());
		}
		TeamB.clear();
		return;
	}

	for (int i = Idx; i <= N; i++) {
		Visit[i] = 1;
		TeamA.push_back(i);

		Dfs(Count + 1, i + 1, G);

		TeamA.pop_back();
		Visit[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> Person[i];
	for (int i = 1; i <= N; i++) {
		//i번 영역에 인접한 영역의 수 = num
		int num; 
		cin >> num;
		for (int j = 1; j <= num; j++) {
			int temp; 
			cin >> temp;
			Node[i].push_back(temp);
		}
	}
	
	for (int i = 1; i <= N / 2; i++) {
		Dfs(0, 1, i);
	} 
	if (Ans == 1e9) cout << -1;
	else cout << Ans;
}