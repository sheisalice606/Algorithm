#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, Ans, Visit[13];
//1-12번째 row 에 해당되는 col 값이 포함됨

bool Check(int Row, int Col) {
    for(int i = 1; i < Row; i++) {
        if(abs(Col - Visit[i]) == abs(Row - i)) return false;
        if(Visit[i] == Col) return false;
    }
    return true;
}

void Dfs(int Count) {
    if(Count == N + 1) {
        Ans++;
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if(Check(Count, i) == true) {
            Visit[Count] = i;
            Dfs(Count + 1);
            Visit[Count] = 0;
        }
    }
    //가능한 곳에 모두 놓아본다.
}

int solution(int n) {
    N = n;
    Dfs(1);
    return Ans;
}






