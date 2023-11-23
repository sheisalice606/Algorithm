#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

string S;
stack<char> Stack;

int Result;

void Solution() {

	int Temp = 1;
	
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '(')
		{
			Temp *= 2;
			Stack.push(S[i]);
		}
		else if (S[i] == '[')
		{
			Temp *= 3;
			Stack.push(S[i]);
		}
		else if (S[i] == ')')
		{
			if (Stack.empty() == true || Stack.top() != '(')
			{
				cout << 0 << '\n';
				return;
			}
			
			if (S[i - 1] == '(')
				Result += Temp;

			Temp /= 2;
			Stack.pop();

		}
		else if (S[i] == ']')
		{
			if (Stack.empty() == true || Stack.top() != '[')
			{
				cout << 0 << '\n';
				return;
			}

			if (S[i - 1] == '[')
				Result += Temp;

			Temp /= 3;
			Stack.pop();
		}
	}


	if(Stack.empty() == true)
		cout << Result << '\n';
	else
		cout << 0 << '\n';

}

int main() {

	cin >> S;
	Solution();
		
}