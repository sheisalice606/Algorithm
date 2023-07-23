#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> Ans(11);
vector<int> Ryan(11);
vector<int> Apeach(11);
int MAX_DIFF = 0;


bool Same_Value() {
    for(int i = 10; i >= 0; i--)
    {
        //새롭게 갱신
        if(Ans[i] < Ryan[i])
        {
            return true;
        }
        else if(Ans[i] > Ryan[i])
        {
            return false;
        }
    }
}

void Check() {
    
    int Ryan_Total = 0;
    int Apeach_Total = 0;
    
    for(int i = 0; i <= 10; i++)
    {
        if(Apeach[i] < Ryan[i]) Ryan_Total += (10 - i);
        else if(Apeach[i] > 0) Apeach_Total += (10 - i);
    }
    
    if(Ryan_Total - Apeach_Total > 0)
    {
        //최대 값 갱신
        if(MAX_DIFF < Ryan_Total - Apeach_Total)
        {
            MAX_DIFF = Ryan_Total - Apeach_Total;
            Ans = Ryan;
        }
        else if(MAX_DIFF == Ryan_Total - Apeach_Total)
        {
            if(Same_Value() == true)
            {
                Ans = Ryan;
            }
        }
    }
    
}

void Dfs(int Count, int Arrow) {
    
    if(Count == 11 || Arrow == 0)
    {
        Ryan[10] = Arrow;
        Check();
        Ryan[10] = 0;
        return;
    }
    
    if(Arrow > Apeach[Count])
    {
        Ryan[Count] = Apeach[Count] + 1;
        Dfs(Count + 1, Arrow - (Apeach[Count] + 1));
        Ryan[Count] = 0;
    }
    
    Dfs(Count + 1, Arrow);
    
}


vector<int> solution(int n, vector<int> info) {
    
    N = n;
    for(int i = 0; i <= 10; i++)
    {
        Apeach[i] = info[i];
    }
    //전역변수 세팅
    
    Dfs(0, N);
    //백 트래킹 -> 모든 경우의 수 고려
    
    if(MAX_DIFF == 0)
    {
        return {-1};
    }
    else
    {
        return Ans;
    }
    
}








