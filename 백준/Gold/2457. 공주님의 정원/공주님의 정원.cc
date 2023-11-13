#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
priority_queue<int> Temp;
int Ans = 1;
int N;
bool Flag = false;


int Make_Day(int M, int D) {
	
	int Cnt = 0;

	if (M == 1) Cnt += 0;
	else if (M == 2) Cnt += 31;
	else if (M == 3) Cnt += 59;
	else if (M == 4) Cnt += 90;
	else if (M == 5) Cnt += 120;
	else if (M == 6) Cnt += 151;
	else if (M == 7) Cnt += 181;
	else if (M == 8) Cnt += 212;
	else if (M == 9) Cnt += 243;
	else if (M == 10) Cnt += 273;
	else if (M == 11) Cnt += 304;
	else if (M == 12) Cnt += 334;

	return Cnt + D;
}

int main() {

	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		PQ.push({ Make_Day(a, b), Make_Day(x, y) });
	}

	int st = 0;
	int en = 0;

	while (!PQ.empty() && PQ.top().first <= 60)
	{
		st = PQ.top().first;
		en = PQ.top().second;
		Temp.push(en);
		PQ.pop();
	}

	if (en > 334)
	{
		Flag = true;
		goto FIN;
	}
	
	if (Temp.size() > 0)
	{
		en = Temp.top();
		while (!Temp.empty()) Temp.pop();
	}
	else
	{
		goto FIN;
	}
	

	//cout << "초기 : " << st << " , " << en << endl;
	
	while (!PQ.empty())
	{

		int curr_st = PQ.top().first;
		int curr_en = PQ.top().second;
		PQ.pop();

		//cout << "현재 : " << curr_st << " , " << curr_en << endl;

		if (curr_st <= en)
		{
			Temp.push(curr_en);
			continue;
		}
		else
		{
			if (Temp.size() > 0)
			{
				en = Temp.top();
				Ans += 1;
				while (!Temp.empty()) Temp.pop();


				if (en > 334)
				{
					Flag = true;
					goto FIN;
				}

				
				//cout << "간선 추가 EN : " << en << endl;

				if (curr_st <= en)
				{
					Temp.push(curr_en);
					continue;
				}
			}
			else
			{
				cout << 0;
				exit(0);
			}
			
		}

	}




	if (Flag == false)
	{
		if (Temp.size() > 0) Ans++;
		if (Temp.top() > 334) Flag = true;
	}
	//마지막 처리


FIN : 

	if (Flag == true) cout << Ans;
	else cout << 0;

}
	