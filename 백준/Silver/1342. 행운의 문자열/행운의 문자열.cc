#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <string>
using namespace std;

string s;
int Len;

map<char, int> M;
int Ans;

void Dfs(string Curr, int Count) {

	if (Count == Len) {
		Ans++;
		return;
	}
	
	for (auto it = M.begin(); it != M.end(); it++) {
		if (it->second == 0) continue;
		if (Curr.back() == it->first) continue;

		it->second--;
		Dfs(Curr + it->first, Count + 1);
		it->second++;
	}
}

int main() {
	cin >> s;
	Len = s.length();

	for (int i = 0; i < Len; i++) {
		M[s[i]]++;
	}

	string start = "";
	for (auto it = M.begin(); it != M.end(); it++) {
		if (it->second > 0) {
			it->second--;
			Dfs(start + it->first, 1);
			it->second++;
		}
	}
	cout << Ans;

}