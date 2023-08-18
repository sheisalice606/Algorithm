#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

int Ans = 9999;

void Check_Zip(string s, int count)
{
    
    string Fin = "";
    
    
    string Temp = s.substr(0, count);
    string Curr = "";
    
    int Same = 0;
    
    int en = 0;
    for(int st = 0; st < s.length(); st++)
    {
        while(en - st < count && en < s.length())
        {
            Curr += s[en];
            en++;
        }
        //en - st = count 상태
        
        if(Curr == Temp)
        {
            if(en != count) Same++;
        }
        else
        {
            if(Same > 0)
            {
                string Insert = to_string(Same + 1) + Temp;
                Fin += Insert;
                Same = 0;
            }
            else if(Same == 0)
            {
                Fin += Temp;
            }
            
            // cout << "next string : " << Curr << endl;
            Temp = Curr;
        }
        
        Curr = "";
        st = en - 1;
        
    }
    // 마지막 문자열 검증 진행
    
    if(Same > 0)
    {
        string Insert = to_string(Same + 1) + Temp;
        Fin += Insert;
        Same = 0;
    }
    else if(Same == 0)
    {
        Fin += Temp;
    }

    
    
    // cout << "Fin : " << Fin << endl << endl;
    Ans = min(Ans, static_cast<int>(Fin.length()));
}


int solution(string s) {
    for(int i = 0; i < s.length(); i++)
    {
        Check_Zip(s, i + 1);
    }
    return Ans;
}