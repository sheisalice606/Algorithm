#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

char Oper[3] = {'-', '+', '*'};
vector<char> OP;
int Visit[3];

string Exp;
long long Ans = 0;






void Update_Max() {
    
    vector<long long> Num_Temp;
    vector<char> Oper_Temp;
    string token = "";
    for(int i = 0; i < Exp.length(); i++)
    {
        if(Exp[i] >= '0' && Exp[i] <= '9') 
        {
            token += Exp[i];
        }
        else
        {
            Num_Temp.push_back((long long)stoi(token));
            Oper_Temp.push_back(Exp[i]);
            token = ""; 
        }
    }
    Num_Temp.push_back((long long)stoi(token)); 
    //Temp 초기화
    
    
    for(int op = 0; op < 3; op++)
    {
        char Curr_OP = OP[op];   

        for(int i = 0; i < Oper_Temp.size(); i++)
        {
            if(Oper_Temp[i] == Curr_OP)
            {
                long long prev = Num_Temp[i];
                long long next = Num_Temp[i + 1];
                
                long long Fin;
                if(Curr_OP == '+') Fin = prev + next;
                else if(Curr_OP == '-') Fin = prev - next;
                else if(Curr_OP == '*') Fin = prev * next;                
                
                Num_Temp[i] = Fin;
                Num_Temp.erase(Num_Temp.begin() + (i + 1));

                Oper_Temp.erase(Oper_Temp.begin() + i);
                i--;
            }
        }
    }

    Ans = max(Ans, abs(Num_Temp[0]));
}


//연산자 모든 경우의 수 조합
void Make_Priority(int Count) {
    if(Count == 3)
    {
        Update_Max();
        return;
    }
    for(int i = 0; i < 3; i++)
    {
        if(Visit[i] == 1) continue;
        
        Visit[i] = 1;
        OP.push_back(Oper[i]);
        
        Make_Priority(Count + 1);
        
        Visit[i] = 0;
        OP.pop_back();
    }
}


long long solution(string expression) {
    Exp = expression;
    Make_Priority(0);
    return Ans;
}


