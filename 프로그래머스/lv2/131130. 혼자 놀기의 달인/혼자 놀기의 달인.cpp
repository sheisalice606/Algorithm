#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Map[101];
int Visit[101];
vector<int> Vector;

void Open_Box(int Num, int Count) {
    
    int Next_Box = Map[Num];
    // Num 번째 상자 속 카드번호
    
    if(Visit[Next_Box] == 0)
    {
        Visit[Next_Box] = 1;
        Open_Box(Next_Box, Count + 1);
    }
    else
    {
        Vector.push_back(Count);
        return;
    }
    
}


int solution(vector<int> cards) {
    
    int N = cards.size();
    for(int i = 1; i <= N; i++)
    {
        Map[i] = cards[i - 1];
    }
    //전역변수 세팅
    
    
    for(int i = 1; i <= N; i++)
    {
        if(Visit[i] == 0)
        {
            Visit[i] = 1;
            Open_Box(i, 1);
        }
    }
    //DFS 탐색
    
    
    sort(Vector.rbegin(), Vector.rend());
    //정렬
    
    if(Vector.size() == 1)
    {
        return 0;
    }
    else
    {
        return Vector[0] * Vector[1];
    }
    //결과 반환
    
}