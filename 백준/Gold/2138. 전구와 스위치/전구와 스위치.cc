#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N;
string A, A2;
string B, B2;

void Change(int idx) {
	if (A2[idx] == '0') A2[idx] = '1';
	else if (A2[idx] == '1') A2[idx] = '0';
}



int main() {

	cin >> N;
	cin >> A;
	cin >> B;
	
	A2 = A;
	B2 = B;

	int Ans = 2e9 + 1;
	int Cnt = 0;
	//정답


	//0번 안누르는 경우
	for (int i = 1; i < N; i++)
	{
		if (A2[i - 1] == B2[i - 1]) continue;
		Change(i - 1);
		Change(i);
		Change(i + 1);
		Cnt++;
	}

	if (A2 == B2) Ans = min(Cnt, Ans);


	//초기화
	A2 = A;
	B2 = B;
	Cnt = 0;


	//0번 누르는 경우
	Change(0);
	Change(1);
	Cnt++;
	for (int i = 1; i < N; i++)
	{
		if (A2[i - 1] == B2[i - 1]) continue;
		Change(i - 1);
		Change(i);
		Change(i + 1);
		Cnt++;
	}

	if (A2 == B2) Ans = min(Cnt, Ans);



	if (Ans == 2e9 + 1) cout << -1;
	else cout << Ans;


}