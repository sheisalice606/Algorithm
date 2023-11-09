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

int N;
int Life[8];
int Weight[8];

int Visit[8];
int Ans = 0;


void Dfs(int Count) {
	
	//충돌 실험 완료
	if (Count == N)
	{
		int Cnt = 0;
		for (int i = 0; i < N; i++)
			if (Life[i] <= 0) Cnt++;
		Ans = max(Ans, Cnt);
		return;
	}
	
	//왼쪽 계란이 깨진지 체크
	//깨져있으면 그냥 통과한다.
	if (Life[Count] <= 0)
	{
		Dfs(Count + 1);
		return;
	}

	bool Flag = false;
	for (int i = 0; i < N; i++)
	{
		if (Count == i || Life[i] <= 0) continue; 
		//다른 계란 두 개 : Count 와 i
		//오른쪽 계란이 깨진지 체크
		//안깨진 계란이 나올때까지 탐색한다.

		Flag = true;
		Life[Count] -= Weight[i];
		Life[i] -= Weight[Count];

		Dfs(Count + 1);

		Life[Count] += Weight[i];
		Life[i] += Weight[Count];
	}

	//왼쪽 계란은 멀쩡하지만
	//멀쩡한 오른쪽 계란이 하나도 없는 경우
	if (Flag == false)
	{
		Dfs(Count + 1);
	}
	
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Life[i] >> Weight[i];
	}
	
	Dfs(0);
	cout << Ans;
}