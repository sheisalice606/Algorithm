#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(vector<int> prices) {
    
    vector<int> Ans;
    for(int i = 0; i < prices.size(); i++)
    {
        int Cnt = 0;
        for(int j = i + 1; j < prices.size(); j++)
        {
            Cnt++;
            if(prices[i] > prices[j]) break; 
        }
        Ans.push_back(Cnt);
    }
    return Ans;
    
}