#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N, L, I;
vector<vector<int>> Vector;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<int> Temp;
		int n;
		cin >> n;
		Temp.push_back(n);
		Vector.push_back(Temp);
	}
	//입력

	int Ans = -1;

	for (int i = 0; i < N; i++)
	{
		//모든 Vector는 내림차순 정렬되어있어야 한다.

		int Top = Vector[i][0];
		int Max_Size = 0;
		int IDX = 0;

		for (int j = 0; j < i; j++)
		{
			int Curr = Vector[j][0];

			if (Curr < Top)
			{
				if (Max_Size < Vector[j].size())
				{
					Max_Size = Vector[j].size();
					IDX = j;
				}
			}
		}
		//최선의 선택과정

		if (Max_Size == 0 && IDX == 0) continue;
		//선택 Vector가 없다면 회귀

		for (int n : Vector[IDX])
		{
			Vector[i].push_back(n);
		}

		if (L < Vector[i].size())
		{
			L = Vector[i].size();
			I = i;
		}
		
	}

	reverse(Vector[I].begin(), Vector[I].end());
	cout << Vector[I].size() << endl;
	for (int n : Vector[I]) cout << n << ' ';

}