#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map<string, int> Map;


bool solution(vector<string> phone_book) {
    

    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size(); i++)
    {
        string s = phone_book[i];
        int len = s.length();
        
        for(int j = i + 1; j < phone_book.size(); j++)
        {
            if(phone_book[j].length() < len) break;
            
            if(phone_book[j].find(s) == string::npos) break;
            
            if(phone_book[j].find(s) == 0) return false;
        }
    }
    
    return true;
    
}









