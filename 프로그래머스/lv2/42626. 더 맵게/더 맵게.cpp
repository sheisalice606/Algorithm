#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {

    int Ans = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    for(int i = 0; i < scoville.size(); i++)
    {
        PQ.push(scoville[i]);
    }
    
    while(PQ.top() < K)
    {
        if(PQ.size() < 2)
        {
            Ans = -1;
            break;
        }

        int First = PQ.top();
        PQ.pop();
        
        int Second = PQ.top();
        PQ.pop();
        
        if(First == 0 && Second == 0)
        {
            Ans = -1;
            break;
        }
        
        int Make = First + 2 * Second;
        PQ.push(Make);
        
        Ans++;
    }
    
    return Ans;
    
}