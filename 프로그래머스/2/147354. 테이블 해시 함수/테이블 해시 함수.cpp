#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> Map;
int N, M, C, Rb, Re;

//1. C번째 컬럼 값 기준 오름차순 정렬
//2. 첫 번째 컬럼 기준 내림차순 정렬
bool Cmp(vector<int> A, vector<int> B) {
    if(A[C - 1] == B[C - 1]) {
        return A[0] > B[0];
    }
    return A[C - 1] < B[C - 1];
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    Map = data, C = col, Rb = row_begin, Re = row_end;
    N = Map.size();     //세로
    M = Map[0].size();  //가로
    //전역화
    sort(Map.begin(), Map.end(), Cmp);
    
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << Map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    int Ans = 0;
    for(int i = Rb - 1; i <= Re - 1; i++) {
        int Si = 0;
        for(int j = 0; j < M; j++) {
            Si += (Map[i][j] % (i + 1));
        }
        Ans ^= Si;
    }
    return Ans;
}





