#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include<unordered_map>
#include<unordered_set>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

long long N, R, C;
long long Size, Cnt;

void Search(int x, int y, long long Size) {
	
	if (Size == 1)
	{
		if (x == R && y == C)
		{
			cout << Cnt;
			exit(0);
		}
	}

	long long next = Size / 2;

	if (R >= x && R < x + next && C >= y && C < y + next)
	{
		Search(x, y, next);
	}
	else if (R >= x && R < x + next && C >= y + next && C < y + Size)
	{
		Cnt += pow(next, 2);
		Search(x, y + next, next);
	}
	else if (R >= x + next && R < x + Size && C >= y && C < y + next)
	{
		Cnt += 2 * pow(next, 2);
		Search(x + next, y, next);
	}
	else
	{
		Cnt += 3 * pow(next, 2);
		Search(x + next, y + next, next);
	}

}

int main() {

	cin >> N >> R >> C;
	Size = pow(2, N);
	Search(0, 0, Size);

}