#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long N;
long long DP[500000][2];

long long solution(vector<int> sequence) {
    
    N = sequence.size();
    vector<long long> V1(N, 0);
    vector<long long> V2(N, 0);
    long long P1 = 1;
    long long P2 = -1;
    
    for(int i = 0; i < N; i++) 
    {
        V1[i] = (long long)(sequence[i] * P1);
        V2[i] = (long long)(sequence[i] * P2);
        P1 *= -1;
        P2 *= -1;
    }
    //각 수열이 완성됨 -> 각 수열의 가장 큰 연속 부분수열의 합을 구하면 된다.
    //두 수열의 Max 를 비교하여 가장 큰 Max 를 선정하면 됨
    
    
    
    
    DP[0][0] = max((long long)0, V1[0]);
    DP[0][1] = max((long long)0, V2[0]);
    
    long long Max_1 = DP[0][0];
    long long Max_2 = DP[0][1];
    
    for(int i = 1; i < N; i++)
    {
        DP[i][0] = max(DP[i - 1][0] + V1[i], V1[i]);
        Max_1 = max(Max_1, DP[i][0]);
        
        DP[i][1] = max(DP[i - 1][1] + V2[i], V2[i]);
        Max_2 = max(Max_2, DP[i][1]);
    }
    
    return max(Max_1, Max_2);
    
}