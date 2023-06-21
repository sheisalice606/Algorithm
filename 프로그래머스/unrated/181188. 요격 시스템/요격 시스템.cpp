#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ;

bool Cmp(vector<int> A, vector<int> B){
    return A[0] < B[0];
    //시작 구간 기준 오름차순 정렬
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), Cmp);
    
    PQ.push(targets[0][1]);
    int Cnt = 1;
    
    for(int i = 1; i < targets.size(); i++)
    {
        int First = targets[i][0];
        int Last = targets[i][1];
        
        if(PQ.top() <= First)
        {
            Cnt++;
            while(!PQ.empty()) PQ.pop();
            PQ.push(Last);
        }
        else
        {
            PQ.push(Last);
        }
        
    }
    
    return Cnt;
}