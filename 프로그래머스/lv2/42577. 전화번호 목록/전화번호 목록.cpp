#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    
    vector<string> Vector = phone_book;
    sort(Vector.begin(), Vector.end());
    //사전순 정렬
    
    for(int i = 0; i < Vector.size() - 1; i++)
    {
        string curr = Vector[i];
        string next = Vector[i+1];
        
        if(curr.length() > next.length()) continue;
        //접두사 가능성이 없는 경우
        
        bool Flag = true;
        for(int j = 0; j < curr.length(); j++)
        {
            if(curr[j] != next[j]) Flag = false; 
        }
        if(Flag == true) return false;
        //접두어 발견
        
    }
    
    return true;
}









