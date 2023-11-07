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
int Map[1001];

int main() {

	cin >> N;
	int Max_H = -1;
	int Max_L = -1;

	int Ans = 0;
	int L, H;

	for (int i = 0; i < N; i++)
	{
		cin >> L >> H;
		Map[L] = H;
		if (Max_H < H)
		{
			Max_H = H;
			Max_L = L;
		}

	} 
	
	
	int Curr = 0;
	for (int i = 1; i < Max_L; i++)
	{
		Curr = max(Curr, Map[i]);
		Ans += Curr;
	}
	
	Curr = 0;
	for (int i = 1000; i > Max_L; i--)
	{
		Curr = max(Curr, Map[i]);
		Ans += Curr;
	}

	cout << Ans + Max_H;

}