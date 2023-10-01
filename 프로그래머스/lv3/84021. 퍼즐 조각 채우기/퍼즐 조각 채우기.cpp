#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int Ans = 0;
int N;
int Map[50][50];

vector<pair<int, int>> Temp;
vector<vector<pair<int, int>>> Data;

int Used[2500];
int Puzzle[50][50];
int Visit[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// 하|싱|우|좌
// 0 1 2 3 

bool Cmp(pair<int, int> A, pair<int, int> B) {
    if(A.first == B.first) return A.second < B.second;
    else return A.first < B.first;
}

void Print() {
    cout << "MAP : " << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << Map[i][j] << ' ';
        }
        cout << endl;
    } cout << endl;
}

void Print_Temp() {
    cout << "TEMP : " << endl;
    for(int i = 0; i < Temp.size(); i++)
    {
        cout << Temp[i].first << " , " << Temp[i].second << endl;
    }
    cout << endl;
}

void Dfs(int x, int y, int lx, int ly) {
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(Visit[nx][ny] == 1 || Puzzle[nx][ny] == 0) continue;
        
        Visit[nx][ny] = 1;
        Temp.push_back({lx + dx[i], ly + dy[i]});
        Dfs(nx, ny, lx + dx[i], ly + dy[i]);
        //원점에서 뻗어나간 방향
    }
}

//시계 방향 회전
void Rotation() {
    int tmp[50][50] = {0};
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            tmp[j][N - i - 1] = Map[i][j];
            
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            Map[i][j] = tmp[i][j];
}

void Match(int x, int y, int lx, int ly) {
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(Visit[nx][ny] == 1 || Map[nx][ny] == 1) continue;
        
        Visit[nx][ny] = 1;
        Temp.push_back({lx + dx[i], ly + dy[i]});
        Match(nx, ny, lx + dx[i], ly + dy[i]);
        //원점에서 뻗어나간 방향
    }
}

void Paint(int x, int y) {
    for(int i = 0; i < Temp.size(); i++)
    {
        int nx = x + Temp[i].first;
        int ny = y + Temp[i].second;
        Map[nx][ny] = 1;
        Ans++;
    }  
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    N = game_board.size();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            Map[i][j] = game_board[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            Puzzle[i][j] = table[i][j];
    //전역변수 세팅

    
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            if(Visit[i][j] == 0 && Puzzle[i][j] == 1)
            {
                Visit[i][j] = 1;
                Temp.push_back({0, 0});
                Dfs(i, j, 0, 0);
                
                sort(Temp.begin(), Temp.end(), Cmp);
                Data.push_back(Temp);
                Temp.clear();
            }
        }   
    memset(Visit, 0, sizeof(Visit));
    //퍼즐 정보 저장
    

    //퍼즐 맞추기
    for(int n = 0; n < 4; n++)
    {   
        Rotation();
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
            {
                
                if(Map[i][j] == 0 && Visit[i][j] == 0)
                {
                    Visit[i][j] = 1;
                    Temp.push_back({0, 0});
                    Match(i, j, 0, 0);               
                    sort(Temp.begin(), Temp.end(), Cmp);
                    
                    for(int k = 0; k < Data.size(); k++)
                    {
                        if(Used[k] == 1) continue;                         
                        if(Temp == Data[k])
                        {
                            Used[k] = 1;
                            Paint(i, j);
                            //cout << "K : " << k << endl;
                            break;
                        }
                    }
                
                    Temp.clear();
                }
            }
        memset(Visit, 0, sizeof(Visit));
    }

    return Ans;
}

















