#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int N;
int Map[11];
int Visit[11];
int Edge[11][11];


vector<int> A;	//백트래킹 조합
vector<int> B;	//A에 해당하지 않는 노드


int Visit_A[11];
vector<int> Ans;


void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> Map[i];
	for (int i = 1; i <= N; i++)
	{
		int Temp; 
		cin >> Temp;
		for (int j = 1; j <= Temp; j++)
		{
			int Node;
			cin >> Node;
			Edge[i][Node] = 1;
		}
	}
}

//선거구의 인구 차이
int Make_Ans() {
	int Sum_A = 0, Sum_B = 0;
	for (int i = 0; i < A.size(); i++)
		Sum_A += Map[A[i]];
	for (int i = 0; i < B.size(); i++)
		Sum_B += Map[B[i]];
	return abs(Sum_A - Sum_B);
}

//각 노드집합이 모두 인접한지 Check
bool Bfs() {

	//A
	queue<int> Q;
	Q.push(A[0]);
	Visit[A[0]] = 1;
	
	while (!Q.empty())
	{
		int curr = Q.front();
		Q.pop();

		for (int i = 0; i < A.size(); i++)
		{
			int next = A[i];
			if (curr == next) continue;				//본인 노드
			if (Edge[curr][next] == 0) continue;	//이어지지 않은 경우
			if (Visit[next] == 1) continue;			//이미 방문한 경우

			Visit[next] = 1;
			Q.push(next);
		}
	}

	for (int i = 0; i < A.size(); i++)
		if (Visit[A[i]] == 0)
			return false;


	//B
	memset(Visit, 0, sizeof(Visit));
	queue<int> Q2;
	Q2.push(B[0]);
	Visit[B[0]] = 1;

	while (!Q2.empty())
	{
		int curr = Q2.front();
		Q2.pop();

		for (int i = 0; i < B.size(); i++)
		{
			int next = B[i];
			if (curr == next) continue;				//본인 노드
			if (Edge[curr][next] == 0) continue;	//이어지지 않은 경우
			if (Visit[next] == 1) continue;			//이미 방문한 경우

			Visit[next] = 1;
			Q2.push(next);
		}
	}

	for (int i = 0; i < B.size(); i++)
		if (Visit[B[i]] == 0)
			return false;


	return true;
}

//A,B 조합 생성
void Dfs(int Count, int Idx, int Goal) {

	if (Count == Goal)
	{
		for (int i = 1; i <= N; i++)
			if (Visit_A[i] == 0)
				B.push_back(i);

		if (Bfs() == true)
			Ans.push_back(Make_Ans());
		
		B.clear();
		memset(Visit, 0, sizeof(Visit));
		return;
	}

	for (int i = Idx; i <= N; i++)
	{
		A.push_back(i);
		Visit_A[i] = 1;

		Dfs(Count + 1, i + 1, Goal);

		Visit_A[i] = 0;
		A.pop_back();
	}

}

int main() {

	Input();
	for (int i = 1; i <= N / 2; i++)
	{
		Dfs(0, 1, i);
		memset(Visit_A, 0, sizeof(Visit_A));
	}
	if (Ans.size() == 0)
	{
		cout << -1;
	}
	else
	{
		sort(Ans.begin(), Ans.end());
		cout << Ans[0];
	}

}