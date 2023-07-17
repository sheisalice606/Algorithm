#include <string>
#include <vector>

using namespace std;

long long N;
vector<int> Vector;
vector<int> Ans;

vector<int> solution(int n, long long left, long long right) {
    
    N = n;
    // 전역 변수 세팅
    
    
    for(long long i = left; i <= right; i++)
    {
        int Row = i / N;
        // 행
        
        int Col = i % N;
        // 열
        
        if(Col <= Row)
        {
            Vector.push_back(Row + 1);
        }
        else
        {
            Vector.push_back(Col + 1);
        }
        
    }
    // 벡터 원소 삽입
    
    
    return Vector;
}