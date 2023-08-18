#include <string>
#include <vector>
#include <stack>

using namespace std;

//쪼갤 수 있는 경우 true
bool Can_Split(string str)
{
    int cnt_1 = 0;
    int cnt_2 = 0;
    int half = str.length() / 2;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(') cnt_1++;
        else if(str[i] == ')') cnt_2++;
        
        if(cnt_1 == cnt_2)
        {
            if(cnt_1 == half && cnt_2 == half) return false;
            else return true;
        }
    }
    
    return false;
}


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
    
    if(cnt_1 == cnt_2) return true;
    else return false;
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
    if(str == "") return "";
    
    if(Check_Count(str) == true && Can_Split(str) == false)
    {
        if(Check_Shape(str) == true)
        {
            return str + Recursion("");
        }
        else
        {
            string N = "(";
            N += Recursion("");
            N += ")";
            
            string Copy_str = str;
            Copy_str.pop_back();
            Copy_str.erase(0, 1);
            
            string reverse_str = Reverse(Copy_str);
            return N + reverse_str;     
        }
    }
    
    
    
    string V = "";
    for(int i = str.length() - 1; i >= 0; i--)
    {
        string U = str.substr(0, i);
        V = str[i] + V;
        
        if(Check_Count(V) == true && Can_Split(U) == false)
        {
            if(Check_Shape(U) == true)
            {
                return U + Recursion(V);
            }
            else
            {
                string N = "(";
                N += Recursion(V);
                N += ")";
                
                string Copy_U = U;
                
                Copy_U.pop_back();
                Copy_U.erase(Copy_U.begin());
                string reverse_U = Reverse(Copy_U);
                
                return N + reverse_U;
            }
        }
    }
    
    
    
}

string solution(string p) {
    return Recursion(p);
}