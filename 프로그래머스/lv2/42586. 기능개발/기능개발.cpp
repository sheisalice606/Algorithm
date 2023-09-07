#include <string>
#include <vector>

using namespace std;

vector<int> Ans;

int Visit[100];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    int Size = progresses.size();
    
    while(Size > 0)
    {
        for(int i = 0; i < progresses.size(); i++)
        {   
            if(Visit[i] == 0)
            {
                progresses[i] += speeds[i];
            }
        }
        //개발 진행
        
        int Cnt = 0;
        for(int i = 0; i < progresses.size(); i++)
        {
            if(Visit[i] == 1) continue;
            
            if(progresses[i] >= 100)
            {
                Cnt++;
                Visit[i] = 1;
                Size--;
                continue;
            }
            else
            {
                break;
            }
        }
        //배포 진행
        
        if(Cnt > 0)
        {
            Ans.push_back(Cnt);
        }
    }
    
    return Ans;
}