#include <string>
#include <stack>
#include <vector>
using namespace std;

int N;
stack<int> Stack;
int Count = 0;

int solution(vector<int> order) {
    
    N = order.size();
    
    int num = 1;
    for(int i = 0; i < N; i++) {
        
        while(true) 
        {
            if(num < order[i]) 
            {
                Stack.push(num);
                num++;
                continue;
            } 
            else if(num == order[i]) 
            {
                Count++;
                num++;
                break;
            }
            else 
            {
                if(Stack.size() > 0 && Stack.top() == order[i])
                {
                    Count++;
                    Stack.pop();
                    break;
                }
                else 
                {
                    goto result;
                }
                
            }
        }
        
        
    }
    
    result :
    return Count;
}