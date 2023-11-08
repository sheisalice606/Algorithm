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
int Fin[1001];
map<string, int> Map;

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string s; cin >> s;
		Map[s] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		string s; cin >> s;
		Fin[i] = Map[s];
		//Fin[i] 이란 i 번째로 탈출한 차량이 들어간 순서
		//즉, 탈출 정보와 입장 정보가 둘 다 들어있다.
	}


	int Cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		//i보다 늦게 탈출한 j 대상
		for (int j = i + 1; j <= N; j++)
		{
			if (Fin[j] < Fin[i])
			{
				//i보다 일찍 들어간 j가 있다면
				Cnt++;
				break;
			}
		}
	}

	cout << Cnt;
	
}