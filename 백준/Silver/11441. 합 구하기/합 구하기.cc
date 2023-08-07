#include<iostream>
#include<vector>
using namespace std;

int N, M;
int Map[100001];
int Sum[100001];

void Fast_IO() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Map[i];
		Sum[i] = Sum[i - 1] + Map[i];
	}
	//O(N)
}


int main()
{
	Fast_IO();
	Input();
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int st, en;
		cin >> st >> en;
		cout << Sum[en] - Sum[st - 1] << '\n';
	}
}