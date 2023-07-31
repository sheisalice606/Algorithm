#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
int Ans;

struct Node {
    char c;
    int idx;
};

vector<Node> Vector;

//인덱스 오름차순 정렬
bool Cmp(Node A, Node B) {
    return A.idx < B.idx;
}

//인덱스 범위 변환 
int Make_Range(int num) {
    if(num < 0) {
        num = N + num;
    }
    return num;
}

//올바른 문자열 여부 확인
bool Check(string str) {
    
    // ( { ) }
    stack<char> Stack;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(') 
        {
            Stack.push('(');
            continue;
        }
        if(str[i] == '{') 
        {
            Stack.push('{');
            continue;
        }
        if(str[i] == '[') 
        {
            Stack.push('[');
            continue;
        }
        
        
        if(Stack.size() == 0) return false;
        
        if(str[i] == ')')
        {
            if(Stack.top() == '(') Stack.pop();
            continue;
        }
        if(str[i] == '}')
        {
            if(Stack.top() == '{') Stack.pop();
            continue;
        }
        if(str[i] == ']')
        {
            if(Stack.top() == '[') Stack.pop();
            continue;
        }
        
        
    }
    
    if(Stack.size() > 0) return false;
    else return true;
    
}

int solution(string s) {
    
    N = s.length();
    //전역 변수 초기화
    
    for(int n = 0; n < N; n++)
    {
        for(int i = 0; i < N; i++) 
        {
            Vector.push_back({s[i], i});
        }
        //문자, 인덱스
        for(auto &E : Vector)
        {
            E.idx -= n;
            E.idx = Make_Range(E.idx);
            //인덱스 변경
        }
        sort(Vector.begin(), Vector.end(), Cmp);
        
        string str = "";
        for(auto &E : Vector)
        {
            str.push_back(E.c);
        }
        //바뀐 문자열 생성
        
        if(Check(str) == true) Ans++;
        Vector.clear();
        
    }
    
    return Ans;
    
}