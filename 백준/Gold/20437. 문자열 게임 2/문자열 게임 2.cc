#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

int T, N;
map<char, vector<int>> Map;
vector<int> Ans;

int main() {

	cin >> T;
	while (T--)
	{
		string s; cin >> s;
		cin >> N;

		for (int i = 0; i < s.length(); i++)
		{
			Map[s[i]].push_back(i);
			if (Map[s[i]].size() == N)
			{
				Ans.push_back(Map[s[i]][N - 1] - Map[s[i]][0] + 1);
				//문자열 길이 저장
				Map[s[i]].erase(Map[s[i]].begin());
				//첫 원소 제거
			}
		}

		if (Ans.size() == 0) cout << -1 << endl;
		else
		{
			sort(Ans.begin(), Ans.end());
			cout << Ans[0] << ' ' << Ans[Ans.size() - 1] << '\n';
		}

		Map.clear();
		Ans.clear();
	}


	
} 