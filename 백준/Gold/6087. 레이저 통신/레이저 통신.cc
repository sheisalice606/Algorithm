#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int W, H;
int MAP[MAX][MAX];
queue<pair<pair<int, int>, pair<int, int> > > Q;
int Mirror[MAX][MAX][4];
bool Visited[MAX][MAX][4];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };
int A, B;
int Answer = INF;

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < 4; k++) {
                Mirror[i][j][k] = INF;
            }
        }
    }
}

void input() {
    cin >> W >> H;
    for (int i = 1; i <= H; i++) {
        string S;
        cin >> S;
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] == '*') {
                MAP[i][j] = -1;
            }
            else if (S[j - 1] == 'C') {
                if (Q.empty()) {
                    Q.push(make_pair(make_pair(i, j), make_pair(0, -1)));
                    for (int k = 0; k < 4; k++) {
                        Mirror[i][j][k] = 0;
                        Visited[i][j][k] = true;
                    }
                }
                else {
                    MAP[i][j] = 1;
                    A = i;
                    B = j;
                }
            }
        }
    }
}

void settings() {
    while (!Q.empty()) {
        int NowY = Q.front().first.first;
        int NowX = Q.front().first.second;
        int NowM = Q.front().second.first;
        int NowD = Q.front().second.second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int NextY = NowY + MoveY[i];
            int NextX = NowX + MoveX[i];
            if ((NextY >= 1) && (NextY <= H) && (NextX >= 1) && (NextX <= W) && (MAP[NextY][NextX] != -1)) {
                if (NowD == -1) {
                    if (Mirror[NextY][NextX][i] > NowM) {
                        Visited[NextY][NextX][i] = true;
                        Mirror[NextY][NextX][i] = NowM;
                        Q.push(make_pair(make_pair(NextY, NextX), make_pair(NowM, i)));
                    }
                }
                else {
                    if (NowD != i) {
                        if (Mirror[NextY][NextX][i] > NowM + 1) {
                            Visited[NextY][NextX][i] = true;
                            Mirror[NextY][NextX][i] = NowM + 1;
                            Q.push(make_pair(make_pair(NextY, NextX), make_pair(NowM + 1, i)));
                        }
                    }
                    else {
                        if (Mirror[NextY][NextX][i] > NowM) {
                            Visited[NextY][NextX][i] = true;
                            Mirror[NextY][NextX][i] = NowM;
                            Q.push(make_pair(make_pair(NextY, NextX), make_pair(NowM, i)));
                        }
                    }
                }
            }
        }
    };

    for (int i = 0; i < 4; i++) {
        if (Visited[A][B][i]) {
            Answer = min(Answer, Mirror[A][B][i]);
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}