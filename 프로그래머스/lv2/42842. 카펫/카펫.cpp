#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int h = 3;
    int w = (brown - (h - 2) * 2) / 2;
    //가능한 모든 조합 : 세로가 점점 길어진다.
    while(w > h)
    {
        w = ( brown - (h - 2) * 2 ) / 2;;
        //가로 세로 갱신
        int in_h = h - 2;
        int in_w = w - 2;
        if((h - 2) * (w - 2) == yellow) return {w, h};
        
        h++;
    }
}