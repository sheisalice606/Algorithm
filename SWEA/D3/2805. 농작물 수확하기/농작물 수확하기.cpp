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

int T, N, Ans;
int Map[50][50];

int main() {

	int Turn = 1;
	cin >> T;
	while (Turn <= T)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			string Temp;
			cin >> Temp;
			for (int j = 0; j < Temp.length(); j++)
			{
				Map[i][j + 1] = Temp[j] - '0';
			}
		}
		//Input


		//상부
		int sz = 0;
		for (int i = 1; i <= N / 2; i++)
		{
			for (int j = (N / 2) + 1 - sz; j <= (N / 2) + 1 + sz; j++)
			{
				Ans += Map[i][j];
			}
			sz++;
		}

		//중부
		for (int i = 1; i <= N; i++)
			Ans += Map[N / 2 + 1][i];


		//하부
		sz = 0;
		for (int i = N; i > N / 2 + 1; i--)
		{
			for (int j = (N / 2) + 1 - sz; j <= (N / 2) + 1 + sz; j++)
			{
				Ans += Map[i][j];
			}
			sz++;
		}


		cout << "#" << Turn++ << ' ' << Ans << '\n';


		memset(Map, 0, sizeof(Map));
		Ans = 0;


	}
	
    return 0;
}