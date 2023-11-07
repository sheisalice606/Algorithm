#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N, M;

struct Room {
	int First;
	int Count;
	vector<pair<int, string>> Element;
};
vector<Room> Vector;

//문자열 사전순 정렬
bool Cmp(pair<int, string> A, pair<int, string> B) {
	return A.second < B.second;
}


int main() {

	cin >> N >> M;
	int Curr; 
	string Name;
	
	// 방이 없으면 생성
	for (int i = 0; i < N; i++)
	{
		cin >> Curr >> Name;
		bool Flag = false;

		for (int k = 0; k < Vector.size(); k++)
		{
			if (Vector[k].Count == 0) continue;
			if (Curr > Vector[k].First + 10 || Curr < Vector[k].First - 10) continue;

			//빈 방 발견
			Vector[k].Count--;
			Vector[k].Element.push_back({ Curr, Name });

			Flag = true;
			break;
		}

		//들어갈 방이 없는 경우
		if (Flag == false)
		{
			Vector.push_back({ Curr, M - 1 });
			Vector[Vector.size() - 1].Element.push_back({ Curr, Name });
		}

	}


	for (int i = 0; i < Vector.size(); i++)
	{
		sort(Vector[i].Element.begin(), Vector[i].Element.end(), Cmp);

		if (Vector[i].Count == 0)
		{
			cout << "Started!" << '\n';
			for (int j = 0; j < Vector[i].Element.size(); j++)
				cout << Vector[i].Element[j].first << ' ' << Vector[i].Element[j].second << '\n';
		}
		else
		{
			cout << "Waiting!" << '\n';
			for (int j = 0; j < Vector[i].Element.size(); j++)
				cout << Vector[i].Element[j].first << ' ' << Vector[i].Element[j].second << '\n';
		}
	}
	//최종 출력


}