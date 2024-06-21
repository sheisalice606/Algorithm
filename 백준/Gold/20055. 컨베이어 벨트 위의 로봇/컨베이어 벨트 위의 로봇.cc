#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

//1. 벨트가 회전한다.

//2. 벨트의 회전방향으로 로봇이 이동할 수 있으면 이동한다. 그 칸에 로봇 없고 내구도 1이상
// N --> 1 방향으로 여부 확인한다.

//3. 올리는 위치에 있는 칸의 내구도가 1 이상인 경우 로봇을 올린다

//4. 내구도가 0인 칸의 수가 K개 이상이면 종료한다.

int N, K;
int Map[201], Ride[201];


void Rotation() {
	int Temp = Map[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		Map[i] = Map[i - 1];
	}
	Map[1] = Temp;

	Temp = Ride[2 * N];
	for (int i = 2 * N; i >= 2; i--) {
		Ride[i] = Ride[i - 1];
	}
	Ride[1] = Temp;
}

void Ride_Off() {
	if (Ride[N] == 1) Ride[N] = 0;
	//정해진 장소에서 하차
}

void Ride_On() {
	if (Map[1] > 0) {
		Map[1]--;
		if (Map[1] == 0) K--;
		//로봇의 탑승으로 인해 내구도가 0이 된 경우
		Ride[1] = 1;
	}
}

void Move_Robot() {
	for (int i = N - 1; i >= 1; i--) {
		if (Ride[i + 1] == 1 || Map[i + 1] == 0) continue;
		if (Ride[i] == 0) continue;
		//로봇이 해당 칸에 타있어야 하고
		//다음 칸의 내구도가 남아있으며, 로봇은 없어야한다.

		Ride[i] = 0;
		Ride[i + 1] = 1;
		Map[i + 1]--;
		if (Map[i + 1] == 0) K--;
	}
}


int main() {
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) cin >> Map[i];
	//입력

	int Time = 1;
	while (true) {

		Rotation();
		Ride_Off();
		//회전 후 즉시 하차한다.

		Move_Robot();
		Ride_Off();
		//로봇의 움직임 후 즉시 하차한다.

		Ride_On();
		if (K <= 0) break;
		//로봇이 탑승한다.

		Time++;
	}

	cout << Time;
}