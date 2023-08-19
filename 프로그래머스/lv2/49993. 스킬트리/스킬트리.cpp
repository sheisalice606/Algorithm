#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int State = 1;
int Ans = 0;

map<char, int> Map;

int solution(string skill, vector<string> skill_trees) {
    
    for(int i = 0; i < skill.length(); i++)
    {
        Map[skill[i]] = i + 1;
    }
    
    for(string S : skill_trees)
    {
        for(int i = 0; i < S.length(); i++)
        {
            char C = S[i]; 
            
            if(State > Map[C]) continue;
            else if(State == Map[C]) 
            {
                State++;
            }
            else if(State < Map[C]) 
            {
                Ans--;
                break;
            }

        }
        Ans++;
        State = 1;
    }
    
    return Ans;
    
}