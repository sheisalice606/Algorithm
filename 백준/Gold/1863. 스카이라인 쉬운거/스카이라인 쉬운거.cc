#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int N;
int Cnt = 0;

vector<pair<int, int>> Vector;
stack<int> Stack;

//좌표 오름차순
bool Cmp(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}

int main() {
	cin >> N;
	Stack.push(0);

	for (int i = 0; i < N; i++)
	{
		int W, H; cin >> W >> H;
		Vector.push_back({ W,H });
	}
	sort(Vector.begin(), Vector.end(), Cmp);

	for (int i = 0; i < N; i++)
	{
		if (Stack.size() == 0)
		{
			Stack.push(Vector[i].second);
		}
		else
		{
			//같으면 POP하지 않는다. 
			while (Vector[i].second < Stack.top() && Stack.size() > 0)
			{
				Cnt++;
				//cout << "Current H : " << Vector[i].second << endl;
				//cout << "POP Element : " << Stack.top() << endl;
				Stack.pop();
			}

			if (Vector[i].second > Stack.top())
				Stack.push(Vector[i].second);
		}
	}

	//0포함
	Cnt += (Stack.size() - 1);
	cout << Cnt;
}