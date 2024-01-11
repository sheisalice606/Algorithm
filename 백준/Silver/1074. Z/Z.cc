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

	if (R >= x && R < x + Size && C >= y && C < y + Size)
	{
		Search(x, y, Size / 2);
		Search(x, y + Size / 2, Size / 2);
		Search(x + Size / 2, y, Size / 2);
		Search(x + Size / 2, y + Size / 2, Size / 2);
	}
	else
	{
		Cnt += Size * Size;
	}
}

int main() {

	cin >> N >> R >> C;
	Size = pow(2, N);
	Search(0, 0, Size);

}