#include <string>
#include <vector>

using namespace std;


int Count = 0;
bool Flag = true;

char A[5] = {'A', 'E', 'I', 'O', 'U'};

void Dfs(string Ans, string word) {
    
    if(Flag == true)
    {
        if(Ans == word)
        {
            Flag = false;
            return;
        }
    
        if(Ans.length() == 5)
        {
            return;
        }
    
        for(int i = 0; i < 5; i++)
        {
            Ans.push_back(A[i]);
            
            if(Flag == true) Count++;
            
            Dfs(Ans, word);
            
            Ans.pop_back();
            
        }
        
    }
    
}

int solution(string word) {
    string Ans = "";
    Dfs(Ans, word);
    return Count;
}