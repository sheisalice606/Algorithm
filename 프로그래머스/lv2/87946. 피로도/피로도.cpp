#include <string>
#include <vector>

using namespace std;

int N, K;
int Visit[8];
int Map[8][2];
int Ans = -999; 

void Dfs(int Count, int K) {
    
    for(int i = 0; i < N; i++)
    {
        if(K < Map[i][0] || Visit[i] == 1) continue;
        
        Visit[i] = 1;

        Dfs(Count + 1, K - Map[i][1]);
        
        Visit[i] = 0;
    }
    //다 살펴봤는데 가능한 경우가 없는 경우
    
    Ans = max(Ans, Count);
    return;
    
}

int solution(int k, vector<vector<int>> dungeons) {
    
    N = dungeons.size();
    K = k;
    
    for(int i = 0; i < N; i++)
    {
        Map[i][0] = dungeons[i][0];
        Map[i][1] = dungeons[i][1];
    }
    //전역변수 세팅
    
    Dfs(0, K);
    //백트래킹
    
    return Ans;
}