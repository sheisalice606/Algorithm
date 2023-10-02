#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

int N, M;
map<int, int> Map;
vector<int> List;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		Map[num]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		List.push_back(num);
	}
	// 값 세팅

	
	for (int num : List)
	{
		cout << Map[num] << ' ';
	}


} 