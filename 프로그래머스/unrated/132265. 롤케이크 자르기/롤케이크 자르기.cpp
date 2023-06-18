#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int, int> Map;
int N;
int Size;

int solution(vector<int> topping) {
    
    N = topping.size();
    
    for(int i = 0; i < N; i++) {
        Map[topping[i]]++;
    }
    for(auto E : Map) {
        if(E.second > 0) {
            Size++;
        }
    }
    //토핑의 종류 수 = Size;
    
    
    set<int> Set;
    int Size_Of_Set = 0;
    
    int Cnt = 0;
    
    for(int i = 0; i < N; i++) {
        int Last = topping.back();
        topping.pop_back();
        Map[Last]--;
        if(Map[Last] == 0) Size--;
        
        Set.insert(Last);
        Size_Of_Set = Set.size();

        if(Size == Size_Of_Set) Cnt++;
    }
    
    return Cnt;
}