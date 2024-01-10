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
#include <sstream>
#include <deque>
using namespace std;

int N, M;
int Visit[20001];
vector<int> Vector[20001];
vector<int> Temp;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		Vector[A].push_back(B);
		Vector[B].push_back(A);
	}
}

pair<int, int> Bfs() {

	queue<pair<int, int>> Q;
	Q.push({ 1, 0 });
	Visit[1] = 1;

	int Max = 0;

	while (!Q.empty()) 
	{
		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop();

		if (Max < time)
		{
			Max = time;
			Temp.clear();
			Temp.push_back(curr);
		}
		else if (Max == time)
		{
			Temp.push_back(curr);
		}

		for (int i = 0; i < Vector[curr].size(); i++)
		{
			int next = Vector[curr][i];
			if (Visit[next] == 1) continue;

			Visit[next] = 1;
			Q.push({ next, time + 1 });
		}
	}

	return { Max, Temp.size()};
}
	
int main() {

	Input();
	pair<int, int> Ans = Bfs();
	sort(Temp.begin(), Temp.end());
	cout << Temp[0] << ' ' << Ans.first << ' ' << Ans.second;

}