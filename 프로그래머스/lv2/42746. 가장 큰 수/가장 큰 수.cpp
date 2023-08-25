#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> Vector;

bool Cmp(string A, string B)
{
    return A + B > B + A;   
}


string solution(vector<int> numbers) {
    for(int n : numbers)
    {
        Vector.push_back(to_string(n));
    }
    sort(Vector.begin(), Vector.end(), Cmp);
    
    if(Vector[0] == "0") return "0";
    
    string Ans = "";
    for(string s : Vector)
    {
        Ans += s;
    }
    
    return Ans;
}








