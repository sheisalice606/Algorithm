#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Ans = 0;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());    
    while(true)
    {
        int element = 
            citations.end() - lower_bound(citations.begin(), citations.end(), Ans);
            
        //cout << Ans << "이상인 원소의 수 : " << element << "개 입니다"<< endl;
        
        if(element >= Ans)
        {
            Ans += 1;
            continue;
        }
        
        return Ans - 1;
    }
}