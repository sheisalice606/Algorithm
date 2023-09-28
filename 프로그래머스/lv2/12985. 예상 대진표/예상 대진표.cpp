#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int time = 2;
    int A = a;
    int B = b;
    
    while(true)
    {   
        if(A % 2 == 0) A = A / 2;
        else A = A / 2 + 1;
        
        if(B % 2 == 0) B = B / 2;
        else B = B / 2 + 1;
        
        if(A == B) return time - 1;
        
        time++;
    }
}