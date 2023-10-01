#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> Stack;

vector<int> solution(vector<int> numbers) {
    vector<int> Ans;
    Stack.push(numbers[numbers.size() - 1]);
    Ans.push_back(-1);
    //초기 값 세팅
    
    for(int i = numbers.size() - 2; i >= 0; i--)
    {
        int curr = numbers[i];
        
        bool Flag = false;
        while(Stack.size() > 0)
        {
            int top = Stack.top();
            if(curr < top)
            {
                Flag = true;
                Ans.push_back(top);
                Stack.push(curr);
                break;
            }
            Stack.pop();
        }
        
        if(Flag == false)
        {
            Ans.push_back(-1);
            Stack.push(curr);
        }
        
    }
    reverse(Ans.begin(), Ans.end());
    return Ans;
    
}