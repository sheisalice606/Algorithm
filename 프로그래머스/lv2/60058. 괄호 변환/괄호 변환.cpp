#include <string>
#include <vector>
#include <stack>

using namespace std;


//균형잡힌 괄호 문자열 여부 확인
bool Check_Count(string str)
{
    int cnt_1 = 0;
    int cnt_2 = 0;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(') cnt_1++;
        else if(str[i] == ')') cnt_2++;
    }
    
    return (cnt_1 == cnt_2);
}

//올바른 괄호 문자열 여부 확인
bool Check_Shape(string str)
{
    stack<char> Stack;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(') 
        {
            Stack.push(str[i]);
        }
        else if(str[i] == ')')
        {
            if(Stack.size() == 0) return false;
            
            Stack.pop();
        }
    }
    
    if(Stack.size() > 0) return false;
    else return true;
}

//괄호 뒤집기
string Reverse(string str)
{
    string Ans = "";
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(') Ans += ")";
        else Ans += "(";
    }
    
    return Ans;
}

string Recursion(string str)
{
    if(str == "")
    {
        return "";
    }
    
    if(Check_Shape(str) == true)
    {
        return str;
    }
    
    int ret = 2;
    string U = str.substr(0, ret);
    string V = str.substr(ret);
    
    while(Check_Count(U) == false)
    {
        ret += 2;
        U = str.substr(0, ret);
        V = str.substr(ret);
    }
    //이 반복문을 탈출하면, U 는 최소길이 균형잡힌 괄호 문자열이다.
    
    if(Check_Shape(U) == true)
    {
        return U + Recursion(V);
    }
    else
    {
        string N = "(" + Recursion(V) + ")";
        string reverse_U = Reverse(U.substr(1, U.length() - 2));
        return N + reverse_U;
    }
    
}

string solution(string p) {
    return Recursion(p);
}