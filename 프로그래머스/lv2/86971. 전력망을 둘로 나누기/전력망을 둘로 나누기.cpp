#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<int> Vector[101]; // [1, 100]
vector<int> Count;

int Visit[101];
int Min = 101;
int Size = 0;

void Dfs(int node, int x, int y) {
    //x 와 y 의 연결 통제
    
    for(int i = 0; i < Vector[node].size(); i++)
    {
        int next = Vector[node][i];
        
        //이미 방문한 노드 + 연결 통제 노드
        if(Visit[next] == 1) continue;
        if(node == x && next == y) continue;
        if(node == y && next == x) continue;
        
        //방문 표기 + 그래프 사이즈 증가
        Visit[next] = 1;
        Size++;
        Dfs(next, x, y);
    }
    
    
}

int solution(int n, vector<vector<int>> wires) {
    
    //트리구조 생성
    for(vector<int> v : wires)
    {
        int from = v[0];
        int to = v[1];
        
        Vector[from].push_back(to);
        Vector[to].push_back(from);
        //양방향 연결
    }
    
    
    for(vector<int> v : wires)
    {
        for(int i = 1; i <= n; i++)
        {
            if(Visit[i] == 0)
            {
                Visit[i] = 1;
                Size++;
                Dfs(i, v[0], v[1]);
                Count.push_back(Size);
                Size = 0;
            }
        }
        
        //최소 값 갱신시도 + 초기화
        Min = min(Min, abs(Count[0] - Count[1]));
        Count.clear();
        memset(Visit, 0, sizeof(Visit));
    }
    
    
    return Min;
}