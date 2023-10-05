#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int N;
vector<int> Ans;
vector<int> Map[101];
vector<int> Temp;
int Visit[101];
bool Flag = false;


void Dfs(int curr, int origin) {
	//i는 1이다.
	for (int i = 0; i < Map[curr].size(); i++)
	{
		int next = Map[curr][i];
		//next : 다음 노드

		//사이클 완성
		if (next == origin)
		{
			Flag = true;
			return;
		}
		
		if (Visit[next] == 1) continue;

		Visit[next] = 1;
		Temp.push_back(next);
		Dfs(next, origin);
		Visit[next] = 0;
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num; cin >> num;
		Map[i].push_back(num);
		if (i == num)
		{
			Visit[i] = 1;
			Ans.push_back(num);
		}
	}
	//데이터 저장

	for (int i = 1; i <= N; i++)
	{
		if (Visit[i] == 0)
		{
			Visit[i] = 1;
			Temp.push_back(i);
			Dfs(i, i);
			Visit[i] = 0;

			if (Flag == true)
				for (int n : Temp)
				{
					Visit[n] = 1;
					Ans.push_back(n);
					//사이클 확정 요소만 Visit
				}

			//초기화
			Temp.clear();
			Flag = false;
		}
	}
	//사이클

	sort(Ans.begin(), Ans.end());
	cout << Ans.size() << '\n';
	for (int n : Ans)
		cout << n << '\n';
	//출력

}