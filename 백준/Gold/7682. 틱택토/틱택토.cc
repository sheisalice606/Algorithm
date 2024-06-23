#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <limits>
#include <stack>
using namespace std;

//1.반드시 첫 번째 사람이 X를 놓고, 두번째 사람이 O를 놓는다.
//2. 누구든지 한 사람의 말이 가로, 세로, 대각선 방향으로 3칸을 잇는데 성공하면 게임은 즉시 끝난다.
//3. 게임판이 가득 차도 게임은 끝난다.


string S;
char Map[10][10];


void Print() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cout << Map[i][j] << ' ';
		} cout << endl;
	}
}

int Bingo(char C)  {
	int result = 0;
	//가로 | 세로
	for (int i = 1; i <= 3; i++) {
		int row = 0;
		int col = 0;
		for (int j = 1; j <= 3; j++) {
			if (Map[i][j] == C) row++;
			if (Map[j][i] == C) col++;
		}
		if (row == 3) result++;
		if (col == 3) result++;
	}

	if (Map[1][3] == C && Map[2][2] == C && Map[3][1] == C) result++;
	if (Map[1][1] == C && Map[2][2] == C && Map[3][3] == C) result++;

	return result;
}

int Count(char C) {
	int result = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (Map[i][j] == C) result++;
		}
	}
	return result;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(NULL);

	while (true) {

		cin >> S;
		if (S == "end") break;
		for (int i = 0; i < 9; i++) {
			int x = i / 3;
			int y = i % 3;
			Map[x + 1][y + 1] = S[i];
		}

		//바둑판이 가득 찬 상황
		if (Count('O') + Count('X') == 9) {
			//X가 하나 많아야 함
			if (Count('O') + 1 == Count('X')) {
				//X빙고인 경우, 1빙고 혹은 2빙고임
				if (Bingo('O') == 0 && (Bingo('X') <= 2)) {
					cout << "valid" << endl;
					continue;
				}
			}
		}
		//바둑판이 가득 차지 않은 상황
		else {
			//X와 O가 같은 경우, O 빙고 마무리여야 한다.
			if (Count('O') == Count('X')) {
				if (Bingo('O') == 1 && Bingo('X') == 0) {
					cout << "valid" << endl;
					continue;
				}
			}
			//X가 하나 많은 경우, X 빙고 마무리여야 한다.
			if (Count('O') + 1 == Count('X')) {
				if (Bingo('O') == 0 && Bingo('X') == 1) {
					cout << "valid" << endl;
					continue;
				}
			}
		}

		cout << "invalid" << endl;

	}

}