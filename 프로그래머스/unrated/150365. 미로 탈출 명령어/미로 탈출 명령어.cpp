#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int X, Y; //출발 지점
int R, C; //도착 지점
int N, M; //세로 가로
int K;    //거리

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
vector<string> Vector;
bool flag = true;

/*

1. [도착 지점 까지의 거리]가 남은 이동횟수보다 큰 경우 [X]
2. [남은 이동횟수 - 도착 지점까지의 거리] 가 홀수인 경우 [X] 
3. d -> l -> r -> u 순으로 DFS 탐색

*/


void Dfs(int x, int y, int time, string str) {
    
    if(flag == true) {
    
        if(time == K)
        {
            if(x == R && y == C)
            {
                Vector.push_back(str);
                flag = false;
            }
            return;
        } 
    
        int Dist = abs(x - R) + abs(y - C); // 현 시점 도착지점까지의 거리
        int Left_Time = K - time;
    
        if(Left_Time < Dist) return;
        if((Left_Time - Dist) % 2 == 1) return;
    
    
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if(nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
        
            if(i == 0) 
            {
                Dfs(nx, ny, time + 1, str + "d");
            }
            else if(i == 1)
            {
                Dfs(nx, ny, time + 1, str + "l");
            }
            else if(i == 2)
            {
                Dfs(nx, ny, time + 1, str + "r");
            }
            else if(i == 3)
            {
                Dfs(nx, ny, time + 1, str + "u");
            }
        }
    }
}


string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    N = n; M = m;
    X = x; Y = y;
    R = r; C = c; K = k; 
    //전역 변수 세팅
    
    string str = "";
    Dfs(X, Y, 0, str);
    //탐색
    
    fin:
    if(Vector.empty() == true) return "impossible";
    return Vector[0];
}