#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int Map[10][10];
map<int, int> M1[10], M2[10], M3[10];

	
//미니 사각형 번호 반환
int Make_Num(int x, int y) {
	if (x <= 3) {
		if (y <= 3) return 1;
		else if (y <= 6) return 2;
		else return 3;
	}
	else if (x <= 6) {
		if (y <= 3) return 4;
		else if (y <= 6) return 5;
		else return 6;
	}
	else {
		if (y <= 3) return 7;
		else if (y <= 6) return 8;
		return 9;
	}
}

//입력과 함께 중복체크
void Input() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> Map[i][j];

			M1[i][Map[i][j]] = 1;
			M2[j][Map[i][j]] = 1;
			M3[Make_Num(i, j)][Map[i][j]] = 1;
		}
	}
}

void Print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << Map[i][j] << ' ';
		}
		cout << endl;
	}
}


void Dfs(int Count) {
	
	//최종 칸까지 모두 채운 경우 출력 후 종료한다.
	if (Count == 81) {
		Print();
		exit(0);
	}

	int x = Count / 9 + 1;
	int y = Count % 9 + 1;

	if (Map[x][y] != 0) {
		Dfs(Count + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (M1[x][i] == 0 && M2[y][i] == 0 && M3[Make_Num(x, y)][i] == 0) {

				M1[x][i] = M2[y][i] = M3[Make_Num(x, y)][i] = 1;
				Map[x][y] = i;
				Dfs(Count + 1);
				Map[x][y] = 0;
				M1[x][i] = M2[y][i] = M3[Make_Num(x, y)][i] = 0;

			}
		}
	}


}

int main() {
	Input();
	Dfs(0);
}