#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

int N, C, Ans;
vector<int> Vector;

void Input() {
	cin >> N >> C;
	for (int i = 1; i <= N; i++)
	{
		int Temp;
		cin >> Temp;
		Vector.push_back(Temp);
	}
	sort(Vector.begin(), Vector.end());
}

int Search() {
	
	int st = 1;
	int en = Vector[Vector.size() - 1] - Vector[0];
	
	while (st <= en)
	{
		int mid = (st + en) / 2;

		int Cnt = 0;
		int Temp = Vector[0];

		for (int i = 0; i < Vector.size(); i++)
		{
			if (Vector[i] - Temp >= mid)
			{
				Cnt++;
				Temp = Vector[i];
			}
		}

		if (Cnt + 1 >= C)
		{
			Ans = mid;
			st = mid + 1;
		}
		else
		{
			en = mid - 1;
		}

	}

	return Ans;
}

int main() {

	Input();
	cout << Search();
	
}