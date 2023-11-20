#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

long long X, Y;
long long D, C;
long long Ans;

int main() {
	
	cin >> X >> Y;
	cin >> D >> C;
	long long Gap = max(X, Y) - min(X, Y);


	if (2 * D < C)
	{
		Ans = (X + Y) * D;
	}
	else
	{

		if (Gap >= 2)
		{
			if (D < C)
			{
				Ans = C * min(X, Y) + Gap * D;
			}
			else
			{
				if (Gap % 2 == 0)
					Ans = C * (min(X, Y) + 2 * (Gap / 2));
				else
					Ans = C * (min(X, Y) + 2 * (Gap / 2)) + D;
			}
		}
		else
		{
			Ans = C * min(X, Y) + Gap * D;
		}

	}

	cout << Ans;
	
}