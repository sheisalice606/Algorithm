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

int N, Ans;
int Map[80000];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];

	for (int i = N - 2; i >= 0; i--)
	{
		if (Map[i] < Map[i + 1]) continue;
		Ans += (Map[i] - Map[i + 1] + 1);
		Map[i] = Map[i + 1] - 1;
	}
	cout << Ans;
}
		