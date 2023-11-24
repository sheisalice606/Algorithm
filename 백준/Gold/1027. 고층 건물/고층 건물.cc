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


int N, Ans;
int Map[50];



int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Map[i];
	//데이터 입력

	
	for (int i = 0; i < N; i++)
	{

		int Count = 0;

		//맨 왼쪽 제외
		if (i > 0)
		{
			Count++;
			double M = (Map[i] - Map[i - 1]) / 1.0;


			for (int j = i - 2; j >= 0; j--)
			{
				//최소 갱신
				if (M > ((double)Map[i] - (double)Map[j]) / (i - j))
				{
					M = ((double)Map[i] - (double)Map[j]) / (i - j);
					Count++;
				}
			}
		}

		
		if (i < N - 1)
		{
			Count++;
			double M = (Map[i + 1] - Map[i]) / 1.0;

			for (int j = i + 2; j < N; j++)
			{
				//최대 갱신
				if (M < ((double)Map[i] - (double)Map[j]) / (i - j))
				{
					M = ((double)Map[i] - (double)Map[j]) / (i - j);
					Count++;
				}
			}
		}

		
		Ans = max(Ans, Count);

	}

	cout << Ans;

}