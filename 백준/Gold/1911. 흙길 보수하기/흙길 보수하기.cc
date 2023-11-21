#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int N, L, Ans;
vector<pair<int, int>> Vector;

int main() {

	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		int From, To;
		cin >> From >> To;
		Vector.push_back({ From, To });
	}
	sort(Vector.begin(), Vector.end());
	//시작 지점 오름차순 정렬

	
	int Point = Vector[0].first;
	int En = Vector[0].second;
	//Point : 널빤지의 끝점
	//En : 최근 웅덩이의 끝점

	for (int i = 1; i < Vector.size(); i++)
	{
		while (Point < En)
		{
			Ans++;
			Point += L;
		}

		En = Vector[i].second;

		if (Point < Vector[i].first)
		{
			Point = Vector[i].first;
		}
	}

	
	while (Point < En)
	{
		Ans++;
		Point += L;
	} //마지막 웅덩이 처리

	cout << Ans;
}