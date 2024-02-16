#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> M1;
map<string, int> M2;
map<string, int> MSame;

int Same;
int Diff;


bool Check(string s) {
    char C1 = s[0];
    char C2 = s[1];
    if(!(C1 >= 'A' && C1 <= 'Z') && !(C1 >= 'a' && C1 <= 'z')) return false;
    if(!(C2 >= 'A' && C2 <= 'Z') && !(C2 >= 'a' && C2 <= 'z')) return false;
    return true;
}

int solution(string str1, string str2) {
    for(int i = 0; i < str1.length() - 1; i++)
    {
        string Temp = str1.substr(i, 2);
        if(Check(Temp) == false) continue;
        
        transform(Temp.begin(), Temp.end(), Temp.begin(), ::toupper);
        M1[Temp]++;
    }
    //STR1 부분집합 생성
    
    for(int i = 0; i < str2.length() - 1; i++)
    {
        string Temp = str2.substr(i, 2);
        if(Check(Temp) == false) continue;
        
        transform(Temp.begin(), Temp.end(), Temp.begin(), ::toupper);
        M2[Temp]++;
    }
    //STR2 부분집합 생성
    
    
    for(auto it = M1.begin(); it != M1.end(); it++)
        for(auto it2 = M2.begin(); it2 != M2.end(); it2++)
            if(it->first == it2->first)
            {
                Same += min(it->second, it2->second);  
                Diff += max(it->second, it2->second);  
                MSame[it->first] = 1;
            }
    //교집합
    
    for(auto it = M1.begin(); it != M1.end(); it++)
        if(MSame[it->first] == 0)
            Diff += it->second;
    
    for(auto it = M2.begin(); it != M2.end(); it++)
        if(MSame[it->first] == 0)
            Diff += it->second;
    //합집합
    
    int Ans;
    if(Same == 0 && Diff == 0) Ans = 65536;
    else
    {
        Ans = (65536 * Same) / Diff;
    }
    
    return Ans;
    //반환
}























