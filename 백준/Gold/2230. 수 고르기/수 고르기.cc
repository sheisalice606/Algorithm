#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <set>
using namespace std;

int N, M, Ans;
vector<int> Vector;
priority_queue<int, vector<int>, greater<int>> PQ;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;
		Vector.push_back(Temp);
	}
	sort(Vector.begin(), Vector.end());


	int en = 0;
	for (int st = 0; st < N; st++)
	{
		if (Vector[en] - Vector[st] >= M)
		{
			PQ.push(Vector[en] - Vector[st]);
			continue;
		}

		while (Vector[en] - Vector[st] < M && en < N - 1) 
			en++;
		
		if (Vector[en] - Vector[st] >= M)
		{
			PQ.push(Vector[en] - Vector[st]);
		}
	}

	cout << PQ.top();

}