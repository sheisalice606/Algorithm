#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int N, M;
int Map[101][101];
int Visit[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int Bfs() {
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{1, 1}, 1});
    Visit[1][1] = 1;
    
    while(!Q.empty())
    {
        int px = Q.front().first.first;
        int py = Q.front().first.second;
        int time = Q.front().second;
        Q.pop();
        
        if(px == N && py == M)
        {
            return time;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if(Visit[nx][ny] == 1 || Map[nx][ny] == 0) continue;
            
            Visit[nx][ny] = 1;
            Q.push({{nx, ny}, time + 1});
        }    
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    N = maps.size();
    M = maps[0].size();
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            Map[i][j] = maps[i-1][j-1];
    //전역변수 세팅
    int Ans = Bfs();
    return Ans;
}