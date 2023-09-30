#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Ans = 1;
vector<pair<int, int>> Vector;
priority_queue<int, vector<int>, greater<int>> PQ;

bool Cmp(pair<int, int> A, pair<int ,int> B) {
    return A.first < B.first;
}

int solution(vector<vector<string>> book_time) {
    
    for(auto E : book_time)
    {
        int start = 60 * stoi(E[0].substr(0,2)) + stoi(E[0].substr(3));
        int last = 60 * stoi(E[1].substr(0,2)) + stoi(E[1].substr(3));
        Vector.push_back({start, last});
    }
    sort(Vector.begin(), Vector.end(), Cmp);
    PQ.push(Vector[0].second);
    
    for(int i = 1; i < Vector.size(); i++)
    {
        int st = Vector[i].first;
        int en = Vector[i].second;
        
        //대실 가능한 경우
        if(st >= PQ.top() + 10)
        {
            PQ.pop();
            PQ.push(en);
        }
        else
        {
            PQ.push(en);
            Ans++;
        }
        
        //Ans = max(Ans, static_cast<int>(PQ.size()));
    }
    
    return Ans;
}







