#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
using namespace std;

char Map[3][3];

void Print() {
	cout << "MAP : " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Map[i][j] << ' ';
		} cout << endl;
	} cout << endl;
}

//가득차면 True
bool Check_Full() {
	int Cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (Map[i][j] == '.') Cnt++;
	return Cnt == 0;
}

//반드시 X와 O가 같거나 X가 1 많아야함
bool Check_Count() {
	int X = 0;
	int O = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == 'X') X++;
			else if (Map[i][j] == 'O') O++;
		}
	
	if (X == O || X == O + 1) return true;
	else return false;
}

bool Full_Fail()
{
	int X = 0;
	int O = 0;
	//가로 검사
	for (int i = 0; i < 3; i++)
	{
		if (Map[i][0] == 'O' && Map[i][1] == 'O' && Map[i][2] == 'O') O++;
		if (Map[i][0] == 'X' && Map[i][1] == 'X' && Map[i][2] == 'X') X++;
	}

	//세로 검사
	for (int i = 0; i < 3; i++)
	{
		if (Map[0][i] == 'O' && Map[1][i] == 'O' && Map[2][i] == 'O') O++;
		if (Map[0][i] == 'X' && Map[1][i] == 'X' && Map[2][i] == 'X') X++;
	}

	//대각선 검사
	if (Map[0][0] == 'O' && Map[1][1] == 'O' && Map[2][2] == 'O') O++;
	if (Map[0][0] == 'X' && Map[1][1] == 'X' && Map[2][2] == 'X') X++;
	if (Map[0][2] == 'O' && Map[1][1] == 'O' && Map[2][0] == 'O') O++;
	if (Map[0][2] == 'X' && Map[1][1] == 'X' && Map[2][0] == 'X') X++;

	if (O > 0) return false;
	else return true;
}

bool Check_One_Bingo() {
	int X = 0;
	int O = 0;
	//가로 검사
	for (int i = 0; i < 3; i++)
	{
		if (Map[i][0] == 'O' && Map[i][1] == 'O' && Map[i][2] == 'O') O++;
		if (Map[i][0] == 'X' && Map[i][1] == 'X' && Map[i][2] == 'X') X++;
	}

	//세로 검사
	for (int i = 0; i < 3; i++)
	{
		if (Map[0][i] == 'O' && Map[1][i] == 'O' && Map[2][i] == 'O') O++;
		if (Map[0][i] == 'X' && Map[1][i] == 'X' && Map[2][i] == 'X') X++;
	}

	//대각선 검사
	if (Map[0][0] == 'O' && Map[1][1] == 'O' && Map[2][2] == 'O') O++;
	if (Map[0][0] == 'X' && Map[1][1] == 'X' && Map[2][2] == 'X') X++;
	if (Map[0][2] == 'O' && Map[1][1] == 'O' && Map[2][0] == 'O') O++;
	if (Map[0][2] == 'X' && Map[1][1] == 'X' && Map[2][0] == 'X') X++;


	int X_Cnt = 0;
	int O_Cnt = 0;
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == 'X') X_Cnt++;
			else if (Map[i][j] == 'O') O_Cnt++;
		}


	//X빙고
	if (X == 1 && O == 0)
		if (X_Cnt == O_Cnt + 1) return true;

	//O빙고
	if (X == 0 && O == 1)
		if (X_Cnt == O_Cnt) return true;

	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	
	while (true)
	{
		string str;
		cin >> str;
		if (str == "end") break;
		memset(Map, 0, sizeof(Map));

		for (int i = 0; i < str.length(); i++)
		{
			int x = i / 3; 
			int y = i % 3;
			Map[x][y] = str[i];
		}

		//1순위 필터 : 갯수
		if (Check_Count() == false)
		{
			cout << "invalid" << '\n';
			continue;
		}


		//2순위 : 가득 참
		if (Check_Full() == true)
		{
			//가득 참 -> O 빙고 -> invalid
			if (Full_Fail() == false)
			{
				cout << "invalid" << '\n';
				continue;
			}
			else
			{
				cout << "valid" << '\n';
				continue;
			}
		}


		if (Check_One_Bingo() == true)
		{
			cout << "valid" << '\n';
			continue;
		}
		else
		{
			cout << "invalid" << '\n';
			continue;
		}

	}



} 