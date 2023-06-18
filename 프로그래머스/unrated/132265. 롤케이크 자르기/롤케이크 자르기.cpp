#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> Map;
map<int, int> Map_2;
int N;
int Size;
int Size_2;

int solution(vector<int> topping) {
    
    N = topping.size();
    
    for(int i = 0; i < N; i++) {
        Map[topping[i]]++;
    }
    Size = Map.size();
    //토핑의 종류 수 = Size;

    int Cnt = 0;
    
    for(int i = 0; i < N; i++) {
        Map[topping[i]]--;
        if(Map[topping[i]] == 0) {
            Map.erase(topping[i]);
        }
        Map_2[topping[i]]++;
        
        Size = Map.size();
        Size_2 = Map_2.size();

        if(Size == Size_2) Cnt++;
    }
    
    return Cnt;
}