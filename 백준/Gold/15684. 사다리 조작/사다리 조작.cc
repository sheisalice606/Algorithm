#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, H;
int Map[31][11], Visit[31][11];
bool Flag = false;


void Input() {
    cin >> N >> M >> H;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        Visit[a][b] = 1;
        //a번 라인에 b와 b+1번 세로줄을 이어주는 사다리
    }
}

bool Simulation() {
    for (int i = 1; i <= N; i++) {
        int current_line = i;
        for (int j = 1; j <= H; j++) {
            if (Visit[j][current_line] == 1) current_line++;
            else if (Visit[j][current_line - 1] == 1) current_line--;
        }
        if (i != current_line) return false;
    }
    return true;
}


void Dfs(int count, int idx, int G) {

    if (count == G) {
        if (Simulation()) Flag = true;
        return;
    }

    for (int i = idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (Visit[i][j] == 1) continue;
            if (j - 1 >= 1 && Visit[i][j - 1] == 1) continue;
            if (j + 1 < N && Visit[i][j + 1] == 1) continue;

            Visit[i][j] = 1;
            Dfs(count + 1, i, G);
            if (Flag) return;
            Visit[i][j] = 0;
        }
    }

}

int main() {
    Input();
    for (int i = 0; i <= 3; i++) {
        Dfs(0, 1, i);
        if (Flag) {
            cout << i;
            exit(0);
        }
    }
    cout << -1;
}