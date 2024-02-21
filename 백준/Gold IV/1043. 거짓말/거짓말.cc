#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int N, M, T, Ans;
int Parent[51];
int Visit[51];
vector<int> Person_True;
vector<vector<int>> Party;

int Find(int x) {
	if (Parent[x] == x) return x;
	return Find(Parent[x]);
}

void Merge(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a > b) Parent[a] = b;
	else Parent[b] = a;
}

void Input() {
	cin >> N >> M;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int Temp;
		cin >> Temp;
		Person_True.push_back(Temp);
	}

	for (int i = 0; i < M; i++)
	{
		int Temp; 
		cin >> Temp;
		vector<int> v;
		for (int j = 0; j < Temp; j++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
		Party.push_back(v);
	}

	for (int i = 1; i <= N; i++) 
		Parent[i] = i;
}

void Make_Union() {
	for (int i = 0; i < Party.size(); i++)
	{
		for (int j = 0; j < Party[i].size() - 1; j++)
		{
			for (int k = j + 1; k < Party[i].size(); k++)
			{
				if (Party[i][j] != Party[i][k])
					Merge(Party[i][j], Party[i][k]);
			}
		}
	}
}

int main() {
	Input();
	Make_Union();
	for (int i = 0; i < Person_True.size(); i++)
	{
		int curr = Person_True[i];
		for (int j = 1; j <= N; j++)
			if (Find(curr) == Find(j))
				Visit[j] = 1;
	}

	for (int i = 0; i < Party.size(); i++)
	{
		bool Flag = true;
		for (int j = 0; j < Party[i].size(); j++)
		{
			if (Visit[Party[i][j]] == 1)
			{
				Flag = false;
				break;
			}
		}
		if (Flag == true)
			Ans++;
	}
	
	cout << Ans;
}