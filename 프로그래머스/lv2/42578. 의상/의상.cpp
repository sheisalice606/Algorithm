#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, vector<string>> Map;

int solution(vector<vector<string>> clothes) {
    for(int i = 0; i < clothes.size(); i++)
    {
        string item = clothes[i][0];
        string cate = clothes[i][1];
        Map[cate].push_back(item);
    }
    
    int sum = 1;
    for(auto E : Map)
    {
        sum *= (E.second.size() + 1);
    }
    return sum - 1;
}