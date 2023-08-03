#include <string>
#include <vector>

using namespace std;

int N;

//최종 값
int Fin_0 = 0;
int Fin_1 = 0;

// 통합된 칸 = 1
int Map[1025][1025];
int Visit[1025][1025];

// 병합 가능 여부
bool Check(int px, int py, int Size) {
    
    int Cnt_0 = 0;
    int Cnt_1 = 0;
    
    int nx = px + Size;
    int ny = py + Size;

    //사각형 순회
    for(int i = px; i < nx; i++)
    {
        for(int j = py; j < ny; j++)
        {
            //이미 병합된 칸을 건드린 경우
            if(Visit[i][j] == 1) return false;
            
            if(Map[i][j] == 0) Cnt_0++;
            else if(Map[i][j] == 1) Cnt_1++;
        }
    }
    
    //병합 가능, 최종 값 증가
    if(Cnt_0 == 0 || Cnt_1 == 0) 
    {
        if(Cnt_0 == 0) Fin_1++;
        else if(Cnt_1 == 0) Fin_0++;
        return true;
    }
    else return false;
}


//병합 : Visit = 1
void Merge(int px, int py, int Size) {
    int nx = px + Size;
    int ny = py + Size;
    for(int i = px; i < nx; i++)
        for(int j = py; j < ny; j++)
            Visit[i][j] = 1;
}


vector<int> solution(vector<vector<int>> arr) {
    
    N = arr.size();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Map[i + 1][j + 1] = arr[i][j];
        }
    }
    //전역 변수 초기화
    
    
    for(int i = 1; i <= N; i *= 2)
    {
        //병합 대상 사각형 한 변의 길이 : N -> N/2 -> N/4 -> ,,,
        int Square = N / i;
        
        //순회 및 병합 작업
        for(int i = 1; i <= N; i += Square)
        {
            for(int j = 1; j <= N; j += Square)
            {
                if(Check(i, j, Square))
                {
                    Merge(i, j, Square);
                }
            }
        } 
        
    }
    
    return {Fin_0, Fin_1};
}