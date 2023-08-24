#include <string>
#include <vector>

using namespace std;

int Ans = 0;
vector<int> Vector[201];
int Visit[201];

void Dfs(int x) {

    for(int i = 0; i < Vector[x].size(); i++)
    {
        int next = Vector[x][i];
        
        if(Visit[next] == 1) continue;
        Visit[next] = 1;
        Dfs(next);
    }
    
}


int solution(int n, vector<vector<int>> computers) {

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(computers[i][j] == 1) //본인 포함 연결
            {
                Vector[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(Visit[i] == 0)
        {
            Visit[i] = 1;
            Dfs(i);
            Ans++;
        }
    }
    
    return Ans;
}













