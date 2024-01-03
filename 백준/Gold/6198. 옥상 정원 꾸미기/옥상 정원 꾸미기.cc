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

long long N;
long long Map[80000];

stack<pair<long long, long long>> Stack;


int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];


	long long Cnt = 0;
	Stack.push({ Map[N - 1], 0 });
	

	for (int i = N - 2; i >= 0; i--)
	{
		long long Curr = Map[i];

		long long Temp = 0;
		while (Stack.empty() == false && Stack.top().first < Curr)
		{
			Temp += (Stack.top().second + 1);
			Stack.pop();
		}

		Cnt += Temp;
		Stack.push({ Curr, Temp });

	}
	

	cout << Cnt;
}
		
