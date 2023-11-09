#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N;
int Map[11];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> Map[i];

	vector<int> Vector;
	Vector.push_back(N);

	for (int i = N - 1; i >= 1; i--)
	{
		int Cnt = 0;
		for (int j = 0; j < Vector.size(); j++)
		{
			if (Vector[j] > i) Cnt++;

			if (Cnt == Map[i])
			{
				Vector.insert(Vector.begin() + j + 1, i);
				break;
			}
			else if (Cnt == Map[i] + 1)
			{
				Vector.insert(Vector.begin() + j, i);
				break;
			}

		}
	}

	for (int n : Vector)
	{
		cout << n << ' ';
	} 
}