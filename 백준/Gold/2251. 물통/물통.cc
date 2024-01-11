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
int Visit[201][201][201];

set<int> Set;

//A B C 현재 용량

void Dfs(int a, int b, int c) {

	if (a == 0)
		Set.insert(c);

	if (Visit[a][b][c] == 1) return;
	Visit[a][b][c] = 1;

	// A->B
	if (a + b <= B) Dfs(0, a + b, c);
	else Dfs(a - (B - b), B, c);

	// A->C
	if (a + c <= C) Dfs(0, b, a + c);
	else Dfs(a - (C - c), b, C);

	// B->C
	if (c + b <= C) Dfs(a, 0, b + c);
	else Dfs(a, b - (C - c), C);

	// B->A
	if(b + a <= A) Dfs(a + b, 0, c);
	else Dfs(A, b - (A - a), c);

	// C->B
	if (b + c <= B) Dfs(a, b + c, 0);
	else Dfs(a, B, c - (B - b));

	// C->A
	if (a + c <= A) Dfs(a + c, b, 0);
	else Dfs(A, b, c - (A - a));

}

int main() {

	cin >> A >> B >> C;
	Dfs(0, 0, C);
	for (int n : Set) cout << n << ' ';
}