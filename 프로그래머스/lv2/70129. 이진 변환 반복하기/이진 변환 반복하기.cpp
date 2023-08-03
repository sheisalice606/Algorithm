#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

string Make_String(int num) {
    string str = "";
    while(num > 0)
    {
        if(num % 2 == 0)
        {
            str = '0' + str;
        }
        else if(num % 2 == 1)
        {
            str = '1' + str;
        }
        
        num /= 2;
    }
    return str;
}

vector<int> solution(string s) {
    int Cnt_String = 0;
    int Cnt = 0;
    while(s != "1")
    {
        
        int len = s.length();
        int count_one = count(s.begin(), s.end(), '1');
        
        //0 제거 수
        Cnt += (len - count_one);
        
        //0 제거 문자열 길이
        len -= (len - count_one);
        

        s = Make_String(len);
        Cnt_String++;
    }
    
    return {Cnt_String, Cnt};
}