#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<string, vector<int>> Visit;
map<string, vector<string>> Map;

vector<vector<string>> Ans;
vector<string> Temp;

int Size;


void Dfs(string From, int Count) {
    
    if(Count == Size)
    {
        Ans.push_back(Temp);
        return;
    }
    
    for(int i = 0; i < Map[From].size(); i++)
    {
        string To = Map[From][i];
        
        if(Visit[From][i] == 1) continue;
        
        Visit[From][i] = 1;
        Temp.push_back(To);
       
        Dfs(To, Count + 1);
        
        Visit[From][i] = 0;
        Temp.pop_back();
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    Size = tickets.size();
    for(int i = 0; i < Size; i++)
    {
        Map[tickets[i][0]].push_back(tickets[i][1]);
        Visit[tickets[i][0]].push_back(0);
    }
    
    for(auto& E : Map)
    {
        sort(E.second.begin(), E.second.end());
    }
    
    Temp.push_back("ICN");
    Dfs("ICN", 0);
    sort(Ans.begin(), Ans.end());
    return Ans[0];
}




















