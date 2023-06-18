#include <string>
#include <vector>
#include <map>

using namespace std;
int N;
//index = [ 0, N-1 ]

int Make_Range(int num) {
    if(num >= N) {
        return num - N;
    }
    return num;
}

int solution(vector<int> elements) {
    
    N = elements.size();
    map<int, int> Map;
    
    //길이 1 인 수열 -> 길이 N 인 수열
    for(int i = 1; i <= N; i++)
    {
        
        for(int n = 0; n < N; n++) // n 번째 원소부터 시작한
        {
            int Sum = 0;
            
            for(int k = 0; k < i; k++) // i 개의 원소
            {
                int Index = Make_Range(n + k);
                Sum += elements[Index];
            }
            
            Map[Sum]++;
            
        }
    }
    
    return Map.size();
}