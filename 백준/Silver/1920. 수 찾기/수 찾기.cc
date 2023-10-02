#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
vector<int> Map;
vector<int> List;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int c; cin >> c;
		Map.push_back(c);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int c; cin >> c;
		List.push_back(c);
	}

	sort(Map.begin(), Map.end());
	//정렬
	
	for (int i = 0; i < M; i++)
	{
		int st = 0;
		int en = N - 1;
		int element = List[i];	

		bool Flag = true;
		while (st <= en)
		{
			int mid = (st + en) / 2;
			if (Map[mid] > element) en = mid - 1;
			else if(Map[mid] < element) st = mid + 1;
			else
			{
				Flag = false;
				break;
			}
		}
		if (Flag == false) cout << 1 << '\n';
		else cout << 0 << '\n';

	}


} 