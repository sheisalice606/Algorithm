#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int Map[101][101];
int Visit[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int Bfs(int sx, int sy, int gx, int gy) {
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{sx, sy}, 0});
    Visit[sx][sy] = 1;
    
    while(!Q.empty())
    {
        int px = Q.front().first.first;
        int py = Q.front().first.second;
        int time = Q.front().second;
        Q.pop();
        
        if(px == gx && py == gy)
        {
            return time / 2;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            
            if(Map[nx][ny] == 0) continue;
            if(Visit[nx][ny] == 1) continue;
            Visit[nx][ny] = 1;
            Q.push({{nx, ny}, time + 1});
        }
    }
    
    return 0;
}

void Print(int N, int M) {
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cout << Map[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                if(i == x1 || i == x2 || j == y1 || j == y2) Map[i][j] = 1; 
        //가장자리 이동 가능
    }
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                if(!(i == x1 || i == x2 || j == y1 || j == y2)) Map[i][j] = 0; 
        //내부 이동 불가능
    }
    
    //Print(20, 20);
    
    int sx = characterX * 2;
    int sy = characterY * 2;
    int gx = itemX * 2;
    int gy = itemY * 2;
    return Bfs(sx, sy, gx, gy);
    
}