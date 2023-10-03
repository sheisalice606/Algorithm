#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

map<int, int> Map;

int A[10000];
int B[10000];
int A2[10000];
int B2[10000];

void Clear() {
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(A2, 0, sizeof(A2));
	memset(B2, 0, sizeof(B2));
	Map.clear();
}

int main() {

	while(true)
	{
		int a; cin >> a;
		if (a == 0) break;

		for (int i = 0; i < a; i++)
		{
			cin >> A[i];
			Map[A[i]]++;
		}

		int b; cin >> b;
		if (b == 0) break;

		for (int i = 0; i < b; i++)
		{
			cin >> B[i];
			Map[B[i]]++;
		}
		//Map[i] = 2 : 교차점

		int sum = 0;
		int idx = 0;
		for (int i = 0; i < a; i++)
		{
			sum += A[i];
			if (Map[A[i]] == 2)
			{
				A2[idx] = sum;
				sum = 0;
				idx++;
				continue;
			}
		}
		A2[idx] = sum;
		
		sum = 0;
		idx = 0;
		for (int i = 0; i < b; i++)
		{
			sum += B[i];
			if (Map[B[i]] == 2)
			{
				B2[idx] = sum;
				sum = 0;
				idx++;
				continue;
			}
		}
		B2[idx] = sum;

		int Ans = 0;
		for (int i = 0; i < 10000; i++)
		{
			Ans += max(A2[i], B2[i]);
		}
		cout << Ans << endl;

		Clear();
	}

}