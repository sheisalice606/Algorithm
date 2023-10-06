#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int N, D, K, C;
int Ans = -1;

vector<int> Vector;
unordered_map<int, int> Map;

int main() {
	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		Vector.push_back(num);
	}
	for (int i = 0; i < K - 1; i++)
	{
		Vector.push_back(Vector[i]);
	}

	Map[C]++;
	for (int i = 0; i < K - 1; i++) Map[Vector[i]]++;
	//초기 K - 1개 원소 삽입


	// 꼬리 원소 삽입 & 머리 원소 삭제
	for (int st = 0; st < N; st++)
	{
		Map[Vector[st + K - 1]]++;
		
		int Cnt = 0;
		for (auto E : Map)
		{
			if (E.second > 0) Cnt++;
		}

		Ans = max(Ans, Cnt);
		Map[Vector[st]]--;
	}

	cout << Ans;
}