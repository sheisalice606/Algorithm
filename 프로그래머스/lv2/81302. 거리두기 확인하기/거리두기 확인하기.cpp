#include <string>
#include <vector>

using namespace std;

int T, N, M;
char Map[6][6];
vector<int> Ans;

//상하 좌우 테스트
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//대각선 테스트
int cx[4] = {1, 1, -1, -1};
int cy[4] = {1, -1, 1, -1};

//맨해튼 거리 2 이내 체크
bool Check_Dist(int x, int y) {
    
    //1 단계 : 상하좌우 체크(맨해튼 거리 1)
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 1 || ny < 1 || nx > 5 || ny > 5) continue;
        
        if(Map[nx][ny] == 'P') return false;
    }
    
    
    //2 단계 : 대각선 체크(맨해튼 거리 2)
    for(int i = 0; i < 4; i++)
    {
        int nx = x + cx[i];
        int ny = y + cy[i];
        //대각선 좌표
        
        if(nx < 1 || ny < 1 || nx > 5 || ny > 5) continue;
        
        //거리두기 대상 발견
        if(Map[nx][ny] == 'P')
        {
            if(i == 0) //우측 하단
            {
                if(!(Map[x + 1][y] == 'X' && Map[x][y + 1] == 'X')) return false;
            }
            else if(i == 1) //좌측 하단
            {
                if(!(Map[x + 1][y] == 'X' && Map[x][y - 1] == 'X')) return false;
            }
            else if(i == 2) //우측 상단
            {
                if(!(Map[x - 1][y] == 'X' && Map[x][y + 1] == 'X')) return false;
            }
            else if(i == 3) // 좌측 상단
            {
                if(!(Map[x - 1][y] == 'X' && Map[x][y - 1] == 'X')) return false;
            }
        }
    }
    
    
    //3단계 2칸 수직, 수평거리 테스트(맨해튼 거리 2)
    for(int i = 0; i < 4; i++)
    {
        int nx = x + 2 * dx[i];
        int ny = y + 2 * dy[i];
        
        if(nx < 1 || ny < 1 || nx > 5 || ny > 5) continue;
        
        if(Map[nx][ny] == 'P')
        {
            if(i == 0)
            {
                if(Map[x + 1][y] != 'X') return false;
            }
            else if(i == 1)
            {
                if(Map[x - 1][y] != 'X') return false;
            }
            else if(i == 2)
            {
                if(Map[x][y + 1] != 'X') return false;
            }
            else if(i == 3)
            {
                if(Map[x][y - 1] != 'X') return false;
            }
        }
    }
    
    
    
    return true;
    
}






vector<int> solution(vector<vector<string>> places) {
    
    T = places.size();         // 5
    N = places[0].size();      // 5
    M = places[0][0].length(); // 5
    
    for(int t = 0; t < T; t++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                Map[i + 1][j + 1] = places[t][i][j];
            }
        }
        //전역 데이터 초기화
        
        
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                if(Map[i][j] == 'P')
                {
                    if(Check_Dist(i, j) == false) 
                    {
                        goto fail;
                    }
                }
            }
        }
        
        goto succ;
        
        
        //거리두기 실패
        fail :
        Ans.push_back(0);
        continue;
        
        //거리두기 성공
        succ :
        Ans.push_back(1);
        continue;
        
    }
    
    return Ans;
    
}