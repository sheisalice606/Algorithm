#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers)
    {
        if(num % 2 == 0) 
        {
            answer.push_back(num + 1);
            continue;
        }
        
        ///111
        
        int idx = 0;
        long long temp = num;
        while(true) {
            if(temp % 2 == 0)
            {
                num += pow(2, idx);
                num -= pow(2, idx - 1);
                answer.push_back(num);
                break;
            }
            
            temp /= 2;
            idx++;
        }
        
    }
    
    return answer;
    
}