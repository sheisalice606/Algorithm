#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int N;
int Map[1000000];
stack<int> Stack;
vector<int> Ans;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];


	for (int i = N - 1; i >= 0; i--)
	{

		while (true)
		{
			if (Stack.empty() == true)
			{
				Ans.push_back(-1);
				Stack.push(Map[i]);
				break;
			}
			
			if (Map[i] < Stack.top())
			{
				Ans.push_back(Stack.top());
				Stack.push(Map[i]);
				break;
			}

			Stack.pop();
		}

	}

	
	for (int i = N - 1; i >= 0; i--) cout << Ans[i] << ' ';

}