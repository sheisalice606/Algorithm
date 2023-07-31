#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
int Ans;
string Str;

//문자열 회전
void Rotation() {
    Str.push_back(Str[0]);
    Str.erase(0, 1);
}

//올바른 문자열 여부 확인
bool Check() {
    
    stack<char> Stack;
    
    for(int i = 0; i < Str.length(); i++)
    {
        if(Str[i] == '(' || Str[i] == '{' || Str[i] == '[') 
        {
            Stack.push(Str[i]);
            continue;
        }
        if(Stack.size() == 0) return false;
        
        if(Str[i] == ')') 
        {
            if(Stack.top() == '(') Stack.pop();        
        }
        else if(Str[i] == '}')
        {
            if(Stack.top() == '{') Stack.pop();
        }
        else if(Str[i] == ']') 
        {
            if(Stack.top() == '[') Stack.pop();
        }
    }
    
    if(Stack.size() > 0) return false;
    else return true;
    
}

int solution(string s) {
    
    N = s.length();
    Str = s;
    //전역 변수 초기화
    
    for(int n = 0; n < N; n++)
    {
        Rotation();
        if(Check() == true) Ans++;
    }
    
    return Ans;
    
}