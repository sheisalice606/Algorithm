#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int w,int h) {
    
    long long Cnt = 0;
    long long Total = static_cast<long long>(w) * h;
    
    for(int px = 0; px < w; px++)
    {
        int nx = px + 1;
        int py =  ceil( (-1.0 * h * px) / w + h); 
        int ny =  floor( (-1.0 * h * nx)  / w + h); 
        Cnt += static_cast<long long>(py - ny);
    }
    return Total - Cnt;
}