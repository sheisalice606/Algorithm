#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector<int> Win[101];
vector<int> Lose[101];

int Visit[101][101];
int Check[101];
int Ans = 0;

//자신 노드 제외
int Check_Count(int n) {
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(Check[i] == 1) cnt++;
    }
    return cnt - 1;
}

void Clear() {
    memset(Visit, 0, sizeof(Visit));
    memset(Check, 0, sizeof(Check));
}

void Winner_Count(int n) {
    for(int i = 0; i < Win[n].size(); i++)
    {
        int next = Win[n][i];
        if(Visit[n][next] == 1) continue; 
        
        Visit[n][next] = 1;
        Winner_Count(next);
    }
    
    Check[n] = 1;
}

void Loser_Count(int n) {
    for(int i = 0; i < Lose[n].size(); i++)
    {
        int next = Lose[n][i];
        if(Visit[n][next] == 1) continue;
        
        Visit[n][next] = 1;
        Loser_Count(next);
    }
    
    Check[n] = 1;
}


int solution(int n, vector<vector<int>> results) {

    
    for(vector<int> v : results)
    {
        int win = v[0];
        int lose = v[1];
        
        Win[win].push_back(lose);
        Lose[lose].push_back(win);
    }
    
    for(int i = 1; i <= n; i++)
    {        
        Winner_Count(i);
        int cnt_A = Check_Count(n);
        Clear();
        
        Loser_Count(i);
        int cnt_B = Check_Count(n);
        Clear();
        
        if(cnt_A + cnt_B == n - 1) 
        {
            Ans++;
        }
    }
   
    return Ans;
}