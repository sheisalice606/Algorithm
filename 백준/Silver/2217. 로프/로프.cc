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
vector<int> Vector;
vector<int> Ans;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n; cin >> n;
		Vector.push_back(n);
	}
	sort(Vector.begin(), Vector.end());

	for (int i = 0; i < N; i++)
	{
		Ans.push_back(Vector[i] * (N - i));
	}
	sort(Ans.rbegin(), Ans.rend());

	cout << Ans[0] << endl;
}