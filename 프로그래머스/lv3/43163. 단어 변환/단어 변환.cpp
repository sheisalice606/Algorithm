#include <string>
#include <vector>
#include <queue>
using namespace std;

int Visit[50];

//한글자 이하만 다를 경우 True
bool Can_Change(string A, string B) {
    int cnt = 0;
    for(int i = 0; i < A.length(); i++)
    {
        if(A[i] != B[i]) cnt++;
    }
    if(cnt <= 1) return true;
    else return false;
}

int Bfs(string begin, string target, vector<string>& words) {
    queue<pair<string, int>> Q;
    Q.push({begin, 0});
    
    while(!Q.empty())
    {
        string curr = Q.front().first;
        int time = Q.front().second;
        Q.pop();
        
        if(curr == target)
        {
            return time;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            string next = words[i];
            
            if(Visit[i] == 1) continue;
            if(Can_Change(curr, next) == false) continue;
            Visit[i] = 1;
            Q.push({next, time + 1});
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    return Bfs(begin, target, words);
}