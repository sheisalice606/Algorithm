#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

string solution(string s) {
    
    string Ans = s;
    bool first = true;
    
    string Temp = "";
    for(int i = 0; i < Ans.length(); i++) {
        if(Ans[i] == ' ') {
            first = true;
        }
        else {
            //첫문자 등장
            if(first == true) {
                //숫자
                if(Ans[i] >= '0' && Ans[i] <= '9') {
                    first = false;
                }
                //대문자
                else if(Ans[i] >= 'A' && Ans[i] <= 'Z') {
                    first = false;
                }
                //소문자 -> 대문자
                else {
                    Ans[i] -= 32;
                    first = false;
                }
            }
            //첫문자가 아니다
            else {
                //대문자 -> 소문자
                if(Ans[i] >= 'A' && Ans[i] <= 'Z') {
                    Ans[i] += 32;
                }
            }
        }
    }
    
    return Ans;
}