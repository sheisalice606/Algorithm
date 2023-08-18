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
    string Result = "";
    
    string Temp = s.substr(0, count);
    int Same = 1;
    
    for(int i = count; i < s.length(); i += count)
    {
        string Curr = s.substr(i, count);
        if(Temp == Curr) Same++;
        else
        {
            if(Same == 1)
            {
                Result += Temp;
            }
            else
            {
                Result += to_string(Same) + Temp;
                Same = 1;
                //cout << "Temp : " << Temp << endl;
            }
            Temp = Curr;
        }
    }
    //마지막 문자열 처리
    
    if(Same == 1)
    {
        Result += Temp;
    }
    else
    {
        Result += to_string(Same) + Temp;
    }
    
    //cout << "Result : " << Result << endl << endl;
    
    int Len = Result.length();
    Ans = min(Ans, Len);
    
}


int solution(string s) {
    for(int i = 0; i <= s.length() / 2; i++)
    {
        Check_Zip(s, i + 1);
    }
    return Ans;
}