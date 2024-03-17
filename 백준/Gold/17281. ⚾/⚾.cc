#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
#include <cmath>
using namespace std;

vector<int> Order;
int N, Ans, Map[50][9];

void Input() {
	cin >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> Map[i][j];
		}

	for (int i = 1; i < 9; i++) 
		Order.push_back(i);
}

void Simulation() {

	int Last = 0;
	int Total = 0;

	for (int i = 0; i < N; i++)
	{
		queue<int> Roo;
		Roo.push(0);
		Roo.push(0);
		Roo.push(0);
		int Out = 3;
		//초기화 & 더미데이터

		while (Out > 0)
		{
			int Curr = Order[Last % 9];

			if (Map[i][Curr] == 0)
			{
				Out--;
			}

			if (Map[i][Curr] == 1)
			{
				if (Roo.front() == 1) Total++;
				Roo.pop();

				Roo.push(1);
			}

			if (Map[i][Curr] == 2)
			{
				if (Roo.front() == 1) Total++;
				Roo.pop();
				if (Roo.front() == 1) Total++;
				Roo.pop();

				Roo.push(1);
				Roo.push(0);
			}

			if (Map[i][Curr] == 3)
			{
				if (Roo.front() == 1) Total++;
				Roo.pop();
				if (Roo.front() == 1) Total++;
				Roo.pop();
				if (Roo.front() == 1) Total++;
				Roo.pop();

				Roo.push(1);
				Roo.push(0);
				Roo.push(0);
			}

			if (Map[i][Curr] == 4)
			{
				Total++;
				if (Roo.front() == 1) Total++;
				Roo.pop();
				if (Roo.front() == 1) Total++;
				Roo.pop();
				if (Roo.front() == 1) Total++;
				Roo.pop();

				Roo.push(0);
				Roo.push(0);
				Roo.push(0);
			}

			Last += 1;
		}
	}

	Ans = max(Ans, Total);
}

void Swap(int i, int j) {
	int Temp = Order[i];
	Order[i] = Order[j];
	Order[j] = Temp;
}

bool Np() {
	int N = Order.size() - 1;
	
	int i = N;
	while (i > 0 && Order[i - 1] >= Order[i]) i--;
	if (i == 0) return false;

	int j = N;
	while (Order[i - 1] >= Order[j]) j--;
	Swap(i - 1, j);

	int k = N;
	while (k > i) Swap(i++, k--);
	return true;
}

int main() {
	Input();

	do {
		Order.insert(Order.begin() + 3, 0);
		Simulation();
		Order.erase(Order.begin() + 3);
	} while (Np());

	cout << Ans << endl;
}