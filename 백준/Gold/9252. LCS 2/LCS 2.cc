#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

string A;
string B;

int LCS[1001][1001];

void Track(int x, int y) {
	
	if (LCS[x][y] == 0) 
		return;

	if (LCS[x][y] == LCS[x][y - 1])
	{
		Track(x, y - 1);
	}
	else if (LCS[x][y] == LCS[x - 1][y])
	{
		Track(x - 1, y);
	}
	else
	{
		Track(x - 1, y - 1);
		cout << A[x - 1];
	}

}

int main() {
	
	cin >> A;
	cin >> B;

	for(int i = 0; i < A.length(); i++)
		for (int j = 0; j < B.length(); j++)
		{
			if (A[i] == B[j])
				LCS[i + 1][j + 1] = LCS[i][j] + 1;
			else
				LCS[i + 1][j + 1] = max(LCS[i + 1][j], LCS[i][j + 1]);
		}


	cout << LCS[A.length()][B.length()] << endl;
	if (LCS[A.length()][B.length()] > 0)
	{
		Track(A.length(), B.length());
	}
	
}