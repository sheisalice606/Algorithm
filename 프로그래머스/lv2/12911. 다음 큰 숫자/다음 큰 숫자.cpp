#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

bool Check(int n, int G) {
    int Cnt = 0;
    for(int i = 0; i < 30; i++)
    {
        if(n & 0x01 << i) Cnt++;
    }
    return Cnt == G;
}

int solution(int n) {
    int Cnt = 0;
    for(int i = 0; i < 30; i++)
    {
        if(n & 0x01 << i) Cnt++;
    }
    //1의 갯수 : Cnt
    
    int num = n + 1;
    while(Check(num, Cnt) == false)
    {
        num++;
    }
    return num;
}
// 1(1) : 10(2) : 100(4) : 1000(8)
// 1이 1개인 경우

// 11(3) : 101(5) : 110(6) : 1001(9) : 1010 : 1100 : 10001
// 1이 2개인 경우

// 111 : 1011 : 1101 : 1110 : 10011 : 10101 : 
// 홀수 : 









