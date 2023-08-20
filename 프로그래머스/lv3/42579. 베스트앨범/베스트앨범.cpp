#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<pair<int, int>>> Map;
unordered_map<string, int> Sum;
vector<int> Ans;

//재생 수가 많은 순 -> 고유 번호가 낮은순으로 내림차순
bool Cmp_1(pair<int, int>& A, pair<int, int>& B) {
    if(A.first == B.first)
    {
        return A.second < B.second;
    }
    return A.first > B.first;
}

//총 재생 수가 많은 순으로 내림차순
bool Cmp_2(pair<string, int>& A, pair<string, int>& B) {
    return A.second > B.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    for(int i = 0; i < genres.size(); i++)
    {
        // {재생수, 고유번호}
        Map[genres[i]].push_back({plays[i], i});
        Sum[genres[i]] += plays[i];
    }
    
    for(auto& E : Map)
    {   //재생 횟수 내림차순 정렬
        sort(E.second.begin(), E.second.end(), Cmp_1);
    }
    
    //총 재생 수 내림차순 정렬
    vector<pair<string, int>> Vector(Sum.begin(), Sum.end());
    sort(Vector.begin(), Vector.end(), Cmp_2);
    
    
    for(int i = 0; i < Vector.size(); i++)
    {
        string Gen = Vector[i].first;
        Ans.push_back(Map[Gen][0].second);
        
        if(Map[Gen].size() > 1) Ans.push_back(Map[Gen][1].second);
    }
    
    return Ans;
}