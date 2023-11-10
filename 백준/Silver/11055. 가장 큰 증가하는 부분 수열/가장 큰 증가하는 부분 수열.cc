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
int Ans[1001];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Map[i];
		Ans[i] = Map[i];
	}
	//기초 세팅


	//i 번째 원소를 마지막으로 하는 LIS
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//해당 원소보다 작은 원소들
			if (Map[i] > Map[j])
			{
				Ans[i] = max(Ans[i], Ans[j] + Map[i]);
			}
		}
	}
	
	int M = 0;
	for (int i = 1; i <= N; i++)
	{
		M = max(M, Ans[i]);
	} cout << M;

}