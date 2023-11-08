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

int N, M;
int Map[100001];
int Visit[100001];
int History[100001];

void Bfs(int n) {

	queue<pair<int, int>> Q; //숫자, 시간
	Visit[n] = 1;
	Q.push({ n, 0 });

	while (!Q.empty())
	{
		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop();

		if (curr == M)
		{
			cout << time << endl;
			return;
		}


		if (curr * 2 <= 100000)
		{
			if (Visit[curr * 2] == 0)
			{
				Visit[curr * 2] = 1;
				History[curr * 2] = curr;
				Q.push({ curr * 2 , time + 1 });
			}
		}
		
		if (curr + 1 <= 100000)
		{
			if (Visit[curr + 1] == 0)
			{
				Visit[curr + 1] = 1;
				History[curr + 1] = curr;
				Q.push({ curr + 1, time + 1 });
			}
		}

		if (curr - 1 >= 0)
		{
			if (Visit[curr - 1] == 0)
			{
				Visit[curr - 1] = 1;
				History[curr - 1] = curr;
				Q.push({ curr - 1, time + 1 });
			}
		}
		

	}
}

int main() {

	cin >> N >> M;
	Bfs(N);
	
	int IDX = M;
	vector<int> Path;
	Path.push_back(IDX);

	while (IDX != N)
	{
		IDX = History[IDX];
		Path.push_back(IDX);
	}
	
	for (int i = Path.size() - 1; i >= 0; i--)
		cout << Path[i] << ' ';


}