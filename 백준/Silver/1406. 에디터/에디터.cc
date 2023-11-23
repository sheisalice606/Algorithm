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
char Com;
list<char> List;

int main() {

	string Temp;
	cin >> Temp;

	for (char C : Temp)
		List.push_back(C);

	auto it = List.end();
	//초기 위치 : 맨 뒤


	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Com;

		if (Com == 'L' && it != List.begin())
		{
			it--;
		}
		else if (Com == 'D' && it != List.end())
		{
			it++;
		}
		else if (Com == 'B' && it != List.begin())
		{
			it--;
			it = List.erase(it);
		}
		else if (Com == 'P')
		{
			char Temp;
			cin >> Temp;
			List.insert(it, Temp);
		}
	}

	for (char c : List)
		cout << c;
}