#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    
    int turn = 1;
    
    while(true)
    {
        int Max = *max_element(priorities.begin(), priorities.end());
        int Curr = priorities[0];
        
        if(Max == Curr)
        {
            if(location == 0)
            {
                break;
            }
            turn += 1;
            if(priorities.size() > 0)
            {
                priorities.erase(priorities.begin());
            }
            location--;
            continue;
        }
        
        priorities.push_back(Curr);
        priorities.erase(priorities.begin());
        
        if(location == 0) 
        {
            location = priorities.size() - 1;
        }
        else
        {
            location--;
        }
    }
    
    return turn;
}