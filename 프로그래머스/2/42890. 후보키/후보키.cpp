#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

int N, M, Ans;
vector<vector<string>> Map;
vector<int> Temp;
vector<vector<int>> Key;

bool Key_Check() {
    map<string, int> Temp_Map;
    
    for(int i = 0; i < N; i++) {
        string curr = "";
        for(int j = 0; j < Temp.size(); j++) {
            curr += Map[i][Temp[j]];
        }
        if(Temp_Map[curr] == 1) return false;
        else Temp_Map[curr] = 1;
    }
    
    return true;
}

bool Duplicate_Check() {
    for(int i = 0; i < Key.size(); i++) {
        map<int, int> Temp_Map;
        bool Flag = false;
        
        for(int j = 0; j < Temp.size(); j++) {
            Temp_Map[Temp[j]] = 1;
        } 
        
        for(int j = 0; j < Key[i].size(); j++) {
            if(Temp_Map[Key[i][j]] == 0) {
                Flag = true;
                break;
            }
        }
        
        if(Flag == false) return false;
    }
    return true;
}


void Dfs(int Count, int Idx, int G) {
    if(Count == G) {
        if(Key_Check() == true && Duplicate_Check() == true) {
            Ans++;
            Key.push_back(Temp);
        }
        return;
    }
    
    for(int i = Idx; i < M; i++) {
        Temp.push_back(i);
        Dfs(Count + 1, i + 1, G);
        Temp.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    Map = relation;
    N = Map.size();
    M = Map[0].size();
    //전역화
    
    for(int i = 1; i <= M; i++) {
        Dfs(0, 0, i);
    }
    
    return Ans;
}


