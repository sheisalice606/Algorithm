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

}