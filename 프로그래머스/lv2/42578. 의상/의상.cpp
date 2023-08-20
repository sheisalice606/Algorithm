#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> Map;

int solution(vector<vector<string>> clothes) {
    for(vector<string> v : clothes)
    {
        Map[v[1]].push_back(v[0]);
    }
    
    int total = 1;
    for(auto E : Map)
    {
        total *= (E.second.size() + 1);
    }
    return total - 1;
    
}