#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
#include <cmath>
using namespace std;

int N;
string Cmd;
map<char, int> Map;
stack<double> Stack;

void Input() {
	cin >> N;
	cin >> Cmd;
	for (int i = 0; i < N; i++)
	{
		int n; 
		cin >> n;
		Map[i + 'A'] = n;
	}
}

int main() {
	Input();
	for (int i = 0; i < Cmd.length(); i++)
	{
		if (Cmd[i] >= 'A' && Cmd[i] <= 'Z')
		{
			Stack.push((double)Map[Cmd[i]]);
		}
		else if(Stack.size() >= 2)
		{
			double second = Stack.top();
			Stack.pop();

			double first = Stack.top();
			Stack.pop();

			if (Cmd[i] == '+')
				Stack.push(first + second);
			else if (Cmd[i] == '-')
				Stack.push(first - second);
			else if (Cmd[i] == '*')
				Stack.push(first * second);
			else if(Cmd[i] == '/')
				Stack.push(first / second);

		}
	}

	cout << fixed;
	cout.precision(2);
	cout << Stack.top();
}