#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
char Map[510][510];
int Visit[510][510][4];

//진행방향 k
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int len = 0;
vector<int> Ans;

//좌표 변환기
pair<int, int> Make_Range(int x, int y) {
    if(x == 0) x = N;
    else if(x == N + 1) x = 1;
    
    if(y == 0) y = M;
    else if(y == M + 1) y = 1;
    
    return {x, y};
}

//방향 전환기
int Change_Dir(char C, int k) {
    if(k == 0)
    {
        if(C == 'S') return 0;
        else if(C == 'L') return 2;
        else if(C == 'R') return 3;
    }
    else if(k == 1)
    {
        if(C == 'S') return 1;
        else if(C == 'L') return 3;
        else if(C == 'R') return 2;
    }
    else if(k == 2)
    {
        if(C == 'S') return 2;
        else if(C == 'L') return 1;
        else if(C == 'R') return 0;
    }
    else if(k == 3)
    {
        if(C == 'S') return 3;
        else if(C == 'L') return 0;
        else if(C == 'R') return 1;
    }
}


void Mirror(int x, int y, int k) {
   
    // 현재 k 방향으로 x, y 에 접근한 상황
    char curr = Map[x][y];
    
    // 다음 방향 -> 다음 좌표
    int nk = Change_Dir(curr, k);  
    pair<int, int> next = Make_Range(x + dx[nk], y + dy[nk]);
    
    // 방문 가능 여부
    if(Visit[next.first][next.second][nk] == 1) return;
    
    // 사이클 길이 증가 + 다음 좌표 전진
    len++;
    Visit[next.first][next.second][nk] = 1;
    Mirror(next.first, next.second, nk);
    
}

vector<int> solution(vector<string> grid) {
    
    N = grid.size();
    M = grid[0].length();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            Map[i + 1][j + 1] = grid[i][j];
        }
    }
    //전역 변수 초기화
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(Visit[i][j][k] == 0)
                {
                    len++;
                    Visit[i][j][k] = 1;
                    Mirror(i, j, k);
                    
                    if(len > 0) 
                    {
                        Ans.push_back(len);
                        len = 0;
                    }
                }
            }
        }
    }
    
    sort(Ans.begin(), Ans.end());
    return Ans;
}