#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string Curr;
int Visit[20];

unordered_map<string, int> Map;

bool Cmp(pair<int, string> A, pair<int, string> B) {
    if(A.first == B.first)
    {
        return A.second > B.second;
    } 
    return A.first > B.first;
}


void Dfs(int Count, int Index, string Str, int Goal) {
    
    if(Count == Goal)
    {
        Map[Str]++;
        return;
    }
    
    //오름차순 & 중복 알파벳 제거
    for(int i = Index; i < Curr.length(); i++)
    {
        if(Visit[i] == 1) continue;
        
        Visit[i] = 1;
        Dfs(Count + 1, i + 1, Str + Curr[i], Goal);
        Visit[i] = 0;
    }
    
}


vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> Ans;
    
    for(string s : orders)
    {
        Curr = s;
        sort(Curr.begin(), Curr.end());
        //문자열 알파벳 순으로 정렬
        
        for(int i = 1; i <= Curr.length(); i++)
        {
            Dfs(0, 0, "", i);
            memset(Visit, 0, sizeof(Visit));
        }
    }
    
    
    
    //[2, 3, 4]
    for(int Goal : course)
    {
        vector<pair<int, string>> Temp;
        
        for(auto E : Map)
        {
            //주문 2명 이상 & 메뉴 Goal 개
            if(E.second >= 2 && E.first.length() == Goal)
            {
                Temp.push_back({E.second, E.first});
            }
        }
        
        //주문건 기준 내림차순
        sort(Temp.begin(), Temp.end(), Cmp);
        
        
        //최대 주문 코스 삽입(복수 가능)
        int Max = Temp[0].first;
        for(auto E : Temp)
        {
            if(Max == E.first) Ans.push_back(E.second);
            else break;
        }
        
    }
    
    
    sort(Ans.begin(), Ans.end());
    return Ans;
    
}










