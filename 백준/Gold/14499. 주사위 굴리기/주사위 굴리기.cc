#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
#include <cmath>
using namespace std;

int N, M, K, Map[20][20], Order[1000];
int X, Y;
int Dice[7];
//모두 0인 상태로 시작한다.

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
//동|서|북|남


void Rolling_Dice(int D) {
	
	//원본 저장
	int d1 = Dice[1], d2 = Dice[2], d3 = Dice[3];
	int d4 = Dice[4], d5 = Dice[5], d6 = Dice[6];

	//움직임 적용
	if (D == 0) {
		//동
		Dice[6] = d3;
		Dice[3] = d1;
		Dice[1] = d4;
		Dice[4] = d6;
	}
	else if (D == 1) {
		//서
		Dice[6] = d4;
		Dice[4] = d1;
		Dice[1] = d3;
		Dice[3] = d6;
	}
	else if (D == 2) {
		//북
		Dice[6] = d2;
		Dice[2] = d1;
		Dice[1] = d5;
		Dice[5] = d6;
	}
	else if (D == 3) {
		//남
		Dice[6] = d5;
		Dice[5] = d1;
		Dice[1] = d2;
		Dice[2] = d6;
	}

}


void Input() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
	//지도 정보 입력

	for (int i = 0; i < K; i++) {
		int n; cin >> n;
		Order[i] = n - 1;
	}
	//명령어 정보 입력
}

int main() {
	Input();
	//cout << "초기 주사위 좌표 : " << X << ", " << Y << endl;

	for (int i = 0; i < K; i++) {
		int dir = Order[i];
		int nx = X + dx[dir];
		int ny = Y + dy[dir];
		//다음 이동 좌표
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			//cout << nx << ", " << ny << " 는 격자 범위를 벗어납니다." << endl;
			continue;
		}

		X = nx;
		Y = ny;
		Rolling_Dice(dir);
		//이동 확정
		
		//cout << "이동 후 지도 값 : " << Map[X][Y] << endl;
		if (Map[X][Y] == 0) {
			Map[X][Y] = Dice[6];
		}
		else {
			Dice[6] = Map[X][Y];
			Map[X][Y] = 0;
		}

		cout << Dice[1] << endl;

	}
}






