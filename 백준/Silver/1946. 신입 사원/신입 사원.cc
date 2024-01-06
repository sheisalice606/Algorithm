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
#include <sstream>
#include <deque>
using namespace std;

int T, N;
pair<int, int> Map[100000];

int main() {
	
	cin >> T;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (T--)
	{
		cin >> N;
		int Cnt = 1;

		for (int i = 0; i < N; i++)
		{
			cin >> Map[i].first >> Map[i].second;
		}
		sort(Map, Map + N);
		//입력 및 정렬

		
		int Min = Map[0].second;
		for (int i = 1; i < N; i++)
		{
			if (Min > Map[i].second)
			{
				Min = Map[i].second;
				Cnt++;
			}
		}


		cout << Cnt << endl;
	}

}