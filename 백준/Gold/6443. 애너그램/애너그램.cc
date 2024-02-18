#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

int N, Size;
string Map[20];
vector<string> Ans;
unordered_map<char, int> M;


void Dfs(int Count, string Curr, int G) {

	if (Count == G)
	{
		Ans.push_back(Curr);
		return;
	}

	for (auto it = M.begin(); it != M.end(); it++)
	{
		if (it->second == 0) continue;
		it->second--;
		Dfs(Count + 1, Curr + it->first, G);
		it->second++;
	}
}


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	//fast_io

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];
	//Input

	for (int i = 0; i < N; i++)
	{
		string curr = Map[i];
		for (int j = 0; j < curr.length(); j++)
		{
			M[curr[j]]++;
		}

		string str = "";
		for (auto it = M.begin(); it != M.end(); it++)
		{
			if (it->second > 0)
			{
				it->second--;
				Dfs(1, str + it->first, curr.length());
				it->second++;
			}
		}

		sort(Ans.begin(), Ans.end());
		for (string s : Ans) 
			cout << s << '\n';

		M.clear();
		Ans.clear();
	}
}