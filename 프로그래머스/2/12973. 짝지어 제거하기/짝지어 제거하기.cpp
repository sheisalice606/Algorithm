#include <iostream>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    stack<char> St;
    int len = s.length();
    
    for(int i = 0; i < len; i++) {
        if(!St.empty() && s[i] == St.top()) {
            St.pop();
        }
        else {
            St.push(s[i]);
        }
    }
    
    if(St.empty()) return 1;
    else return 0;
}