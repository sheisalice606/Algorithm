#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int N;
int Ans = 2000000001;
vector<int> P;
vector<int> M;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	int First, Second;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		if (num > 0) P.push_back(num);
		else if (num < 0) M.push_back(num);
	}
	if (P.size() == 0)
	{
		cout << M[M.size() - 2] << ' ' << M[M.size() - 1];
		exit(0);
	}
	else if (M.size() == 0)
	{
		cout << P[0] << ' ' << P[1];
		exit(0);
	}
	
	
	int st = 0;
	int en = P.size() - 1;

	while (true)
	{
		int curr = M[st] + P[en];
		if (Ans > abs(curr))
		{
			First = M[st];
			Second = P[en];
			Ans = abs(curr);
		}
		if (Ans == 0) break;

		else if (curr < 0)
		{
			if (st < M.size() - 1) st++;
			else break;
		}
		else if (curr > 0)
		{
			if (en > 0) en--;
			else break;
		}
	}

	if (P[0] + P[1] < Ans)
	{
		First = P[0];
		Second = P[1];
	}

	if (abs(M[M.size() - 1] + M[M.size() - 2]) < Ans)
	{
		First = M[M.size() - 2];
		Second = M[M.size() - 1];
	}

	cout << First << ' ' << Second;
	exit(0);

} 