#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <set>
using namespace std;

int T;

int main() {

	int Turn = 1;
	cin >> T;

	while (Turn <= T)
	{
		
		string Temp;
		cin >> Temp;

		string S = "";
		for (int i = 0; i < Temp.length(); i++) 
			S += "0";
		//기초 세팅

		int Ans = 0;
		for (int i = 0; i < Temp.length(); i++)
		{
			if (S[i] != Temp[i])
			{
				for (int j = i; j < Temp.length(); j++) S[j] = Temp[i];
				Ans++;
			}
			if (S == Temp) break;
		}

		//정답 출력
		cout << "#" << Turn++ << ' ';
		cout << Ans << '\n';

	}

	return 0;

}