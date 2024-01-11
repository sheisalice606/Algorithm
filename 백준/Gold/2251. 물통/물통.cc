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
#include <set>
#include <sstream>
#include <deque>
using namespace std;

int A, B, C;
set<int> Set;
int Visit[201][201][201];
//A B C 현재 용량

void Dfs(int a, int b, int c) {

	if (a == 0)
		Set.insert(c);

	if(a > 0)
	{
		//A -> B
		if (a + b <= B)
		{
			if (Visit[0][a + b][c] == 0)
			{
				Visit[0][a + b][c] = 1;
				Dfs(0, a + b, c);
			}
		}
		else
		{
			if (Visit[a - (B - b)][B][c] == 0)
			{
				Visit[a - (B - b)][B][c] = 1;
				Dfs(a - (B - b), B, c);
			}
		}

		//A -> C
		if (a + c <= C)
		{
			if (Visit[0][b][a + c] == 0)
			{
				Visit[0][b][a + c] = 1;
				Dfs(0, b, a + c);
			}
		}
		else
		{
			if (Visit[a - (C - c)][b][C] == 0)
			{
				Visit[a - (C - c)][b][C] = 1;
				Dfs(a - (C - c), b, C);
			}
		}
	}

	//B

	if (b > 0)
	{
		//B -> C
		if (c + b <= C)
		{
			if (Visit[a][0][b + c] == 0)
			{
				Visit[a][0][b + c] = 1;
				Dfs(a, 0, b + c);
			}
		}
		else
		{
			if (Visit[a][b - (C - c)][C] == 0)
			{
				Visit[a][b - (C - c)][C] = 1;
				Dfs(a, b - (C - c), C);
			}
		}

		//B -> A
		if (b + a <= A)
		{
			if (Visit[a + b][0][c] == 0)
			{
				Visit[a + b][0][c] = 1;
				Dfs(a + b, 0, c);
			}
		}
		else
		{
			if (Visit[A][b - (A - a)][c] == 0)
			{
				Visit[A][b - (A - a)][c] = 1;
				Dfs(A, b - (A - a), c);
			}
		}

	}

	//C

	if (c > 0)
	{
		//C -> B
		if (b + c <= B)
		{
			if (Visit[a][b + c][0] == 0)
			{
				Visit[a][b + c][0] = 1;
				Dfs(a, b + c, 0);
			}
		}
		else
		{
			if (Visit[a][B][c - (B - b)] == 0)
			{
				Visit[a][B][c - (B - b)] = 1;
				Dfs(a, B, c - (B - b));
			}
		}

		//C -> A
		if (a + c <= A)
		{
			if (Visit[a + c][b][0] == 0)
			{
				Visit[a + c][b][0] = 1;
				Dfs(a + c, b, 0);
			}
		}
		else
		{
			if (Visit[A][b][c - (A - a)] == 0)
			{
				Visit[A][b][c - (A - a)] = 1;
				Dfs(A, b, c - (A - a));
			}
		}
			
	}


}

int main() {

	cin >> A >> B >> C;
	Dfs(0, 0, C);
	Set.insert(C);
	for (int n : Set) cout << n << ' ';
}