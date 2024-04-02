#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int N, M, K;
int Fish_King = 0;
int Fish_Point = 0;

struct Data {
	int x;
	int y;
	int speed;
	int dir;
	int size;
};
vector<Data> Shark;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };
// 1 : 위 // 2 : 아래 // 3 : 오른쪽 // 4 : 왼쪽

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x, y, speed, dir, size;
		cin >> x >> y >> speed >> dir >> size;
		Shark.push_back({ x, y, speed, dir, size });
	}
}


void Move_Shark() {

	int Map[101][101];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			Map[i][j] = -1;
	//Temp

	for (int i = 0; i < Shark.size(); i++) {

		int x = Shark[i].x;
		int y = Shark[i].y;
		int speed = Shark[i].speed;
		int dir = Shark[i].dir;
		int size = Shark[i].size;
		//상어 정보 추출

		//cout << "FROM : " << x << ", " << y << endl;

		int pos = -1;
		if (dir == 1) {
			pos = speed % ((2 * N) - 2);
			x -= pos;
			if (x < 1) {
				x = 2 - x;
				dir = 2;
			}
			if (x > N) {
				x = 2 * N - x;
				dir = 1;
			}
		}
		else if (dir == 2) {
			pos = speed % ((2 * N) - 2);
			x += pos;
			if (x > N) {
				x = 2 * N - x;
				dir = 1;
			}
			if (x < 1) {
				x = 2 - x;
				dir = 2;
			}
		}
		else if (dir == 3) {
			pos = speed % ((2 * M) - 2);
			y += pos;
			if (y > M) {
				y = 2 * M - y;
				dir = 4;
			}
			if (y < 1) {
				y = 2 - y;
				dir = 3;
			}
		}
		else if (dir == 4) {
			pos = speed % ((2 * M) - 2);
			y -= pos;
			if (y < 1) {
				y = 2 - y;
				dir = 3;
			}
			if (y > M) {
				y = 2 * M - y;
				dir = 4;
			}
		}
		//좌표, 방향 이동

		//cout << "To : " << x << ", " << y << endl;
		Shark[i].x = x;
		Shark[i].y = y;
		Shark[i].dir = dir;
		//동기화


		if (Map[x][y] == -1 || (Map[x][y] != -1 && Shark[Map[x][y]].size < size)) {
			Map[x][y] = i;
		}
		//New Shark 저장
	}


	vector<Data> newShark;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j] != -1) {
				newShark.push_back(Shark[Map[i][j]]);
			}
		}
	}

	Shark = newShark;
	//상어배열 갱신
}


int main() {
	Input();
	while (Fish_King <= M) {

		//1.낚시왕이 오른쪽으로 한 칸 이동한다.
		Fish_King++;

		//cout << Fish_King << endl << endl;
		
		//2. 물고기 잡기
		int minRow = 1e9;
		int Idx = -1;
		for (int i = 0; i < Shark.size(); i++) {
			if (Shark[i].y == Fish_King && Shark[i].x < minRow) {
				minRow = Shark[i].x;
				Idx = i;
			}
		}

		if (Idx != -1) {
			//cout << "CATCH : " << Shark[Idx].x << " , " << Fish_King << endl;
			Fish_Point += Shark[Idx].size;
			Shark.erase(Shark.begin() + Idx);
			
		}
		//잡을 물고기가 있으면 삭제하고 포인트 추가


		//3. 상어 이동
		Move_Shark();

	}

	cout << Fish_Point << endl;
}