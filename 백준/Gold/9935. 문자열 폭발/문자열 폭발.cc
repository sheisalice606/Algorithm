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
#include <sstream>
#include <deque>
using namespace std;


string S;
string Bomb;

stack<char> Stack;


int main() {

	cin >> S;
	cin >> Bomb;

	char Last = Bomb[Bomb.length() - 1];
	reverse(Bomb.begin(), Bomb.end());

	//ba21

	for (int i = 0; i < S.length(); i++)
	{
		Stack.push(S[i]);
		
		while (Stack.size() >= Bomb.length() && Stack.top() == Last)
		{

			string Temp = "";

			for (int j = 0; j < Bomb.length(); j++)
			{
				Temp += Stack.top();
				Stack.pop();
			}
			

			if (Temp != Bomb)
			{
				for (int j = Temp.length() - 1; j >= 0; j--)
				{
					Stack.push(Temp[j]);
				}

				break;
			}

		}

	}


	string Ans = "";

	while (!Stack.empty())
	{
		Ans += Stack.top();
		Stack.pop();
	}
	
	if (Ans.length() == 0)
		cout << "FRULA";
	else
	{
		for (int i = Ans.length() - 1; i >= 0; i--)
			cout << Ans[i];
	}


}