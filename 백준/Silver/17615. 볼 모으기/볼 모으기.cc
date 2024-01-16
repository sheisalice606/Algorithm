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

int N, R, B, Ans = 2e9 + 1;
string Ball;

int main() {
	
	cin >> N;
	cin >> Ball;
	for (int i = 0; i < N; i++)
	{
		if (Ball[i] == 'R') R++;
		else B++;
	}

	if (R == N || B == N)
	{
		cout << 0;
		exit(0);
	}


	//1. 왼쪽 R
	int Cnt = 0;
	bool Flag = false;
	for (int i = 0; i < R; i++)
	{
		if (Ball[i] == 'B') Flag = true;
		if (Flag == true) Cnt++;
	}

	Ans = min(Ans, Cnt);

	//2. 왼쪽 B
	Cnt = 0;
	Flag = false;
	for (int i = 0; i < B; i++)
	{
		if (Ball[i] == 'R') Flag = true;
		if (Flag == true) Cnt++;
	}

	Ans = min(Ans, Cnt);
	

	//3. 오른쪽 R
	Cnt = 0;
	Flag = false;
	for (int i = 0; i < R; i++)
	{
		if (Ball[N - 1 - i] == 'B') Flag = true;
		if (Flag == true) Cnt++;
	}

	Ans = min(Ans, Cnt);

	//4. 오른쪽 B
	Cnt = 0;
	Flag = false;
	for (int i = 0; i < B; i++)
	{
		if (Ball[N - 1 - i] == 'R') Flag = true;
		if (Flag == true) Cnt++;
	}

	Ans = min(Ans, Cnt);
	cout << Ans;
}