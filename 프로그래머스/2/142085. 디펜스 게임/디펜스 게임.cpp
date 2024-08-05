#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int Sum, N, K, Ans = 1e9;
priority_queue<int> PQ;

int solution(int n, int k, vector<int> enemy) {
    int sz = enemy.size();
    N = n, K = k;
    //전역화
    
    for(int i = 0; i < sz; i++) {
        Sum += enemy[i];
        PQ.push(enemy[i]);
        //일단 넣고 더한다.
        
        while(!PQ.empty() && Sum > n && K > 0) {
            Sum -= PQ.top();
            if(Sum < 0) Sum = 0;
            
            PQ.pop();
            K--;
        } 
        // n보다 커진 경우
        // 무적권 여유가 남은 경우 pop한다.
        
        if(Sum > n && K == 0) {
            Ans = i;
            break;
        }
    }
    
    if(Ans == 1e9) Ans = sz;
    return Ans;
}






