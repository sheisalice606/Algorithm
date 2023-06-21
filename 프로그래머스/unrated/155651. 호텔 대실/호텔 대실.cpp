#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ;


int solution(vector<vector<string>> book_time) {
    int N = book_time.size();
    sort(book_time.begin(), book_time.end());
    //시작 시간 순으로 오름차순 정렬
    
    int Cnt = 1;  
    PQ.push(stoi(book_time[0][1].substr(0, 2)) * 60 + stoi(book_time[0][1].substr(3)));
    
    
    for(int i = 1; i < N; i++)
    {
        int First = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3));
        int Last = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3));  
        
        if(PQ.top() + 10 <= First)
        {
            PQ.pop();
            PQ.push(Last);
        }
        else
        {
            Cnt++;
            PQ.push(Last);
        }
    }
    
    
    return Cnt;
    
    
}