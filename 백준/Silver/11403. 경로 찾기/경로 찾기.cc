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

int N;
int Map[101][101];
int Visit[101];
vector<int> Vector[101];



void Dfs(int x) {
	for (int i = 0; i < Vector[x].size(); i++)
	{
		int next = Vector[x][i];
		if (Visit[next] == 1) continue;
		Visit[next] = 1;
		Dfs(next);
	}
}


int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 1)
				Vector[i].push_back(j);
		}
		

	for (int i = 1; i <= N; i++)
	{
		Dfs(i);
		for (int j = 1; j <= N; j++)
			if (Visit[j] == 1)
				Map[i][j] = 1;

		memset(Visit, 0, sizeof(Visit));
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << ' ';
		}
		cout << endl;
	}
}