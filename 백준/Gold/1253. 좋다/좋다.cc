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

int N, Ans;
int Map[2000];


int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
	}
	sort(Map, Map + N);
	
	for (int i = 0; i < N; i++)
	{
		int st = 0, en = N - 1;
		int Curr = Map[i];

		while (st < en)
		{
			int Sum = Map[st] + Map[en];

			if (Sum < Curr)
			{
				st++;
				//Sum 증가
			}
			else if (Sum > Curr)
			{
				en--;
				//Sum 감소
			}
			if (Sum == Curr)
			{
				if (st != i && en != i)
				{
					Ans++;
					break;
				}
				else if (st == i)
				{
					st++;
				}
				else if (en == i)
				{
					en--;
				}
			}
		}
	}
	cout << Ans;
}