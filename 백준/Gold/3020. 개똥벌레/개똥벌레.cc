#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

int N, H;
int Top[500001];
int Bot[500001];

int main() {

	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		int T; cin >> T;
		if (i % 2 == 0) Bot[T]++; //석순 끝
		else Top[H - T + 1]++;	      //종유석 끝
	}
	//데이터 저장

	for (int i = 1; i < H; i++)
		Top[i + 1] += Top[i];

	for (int i = H; i > 1; i--)
		Bot[i - 1] += Bot[i];
	//누적 합

	int Ans = 987654321;
	int Cnt = 1;
	for (int i = 1; i <= H; i++)
	{
		if (Ans > Top[i] + Bot[i])
		{
			Ans = Top[i] + Bot[i];
			Cnt = 1;
		}
		else if (Ans == Top[i] + Bot[i])
		{
			Cnt++;
		}
	}
	cout << Ans << ' ' << Cnt;

}