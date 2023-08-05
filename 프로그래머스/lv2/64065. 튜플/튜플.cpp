#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> Vector;
vector<int> Ans;
int Visit[100001];

bool Cmp(vector<int> &A, vector<int> &B) {
    return A.size() < B.size();
}


vector<int> solution(string s) {
    
    vector<int> Temp;
    bool Flag = false;
    string token = "";
    
    for(int i = 1; i < s.length() - 1; i++)
    {
        
        if(s[i] == '{') 
        {
            Flag = true;
            continue;
        }
        
        if(Flag == false) continue;
        
        if(s[i] == '}')
        {
            Temp.push_back(stoi(token));
            //해당 집합의 마지막 원소까지 삽입
            Vector.push_back(Temp);
            //해당 집합 삽입
            
            Temp.clear();
            token = "";
            Flag = false;
            continue;
        }
        
        if(isdigit(s[i]) == true)
        {
            token += s[i];
            continue;
        }
        else if(s[i] == ',')
        {
            Temp.push_back(stoi(token));
            token = "";
            continue;
        }

    }
    //vector<vector<int>> 데이터 수집완료
    
    sort(Vector.begin(), Vector.end(), Cmp);
    //vector<int> 요소의 크기 순 정렬
    
    for(int i = 0; i < Vector.size(); i++)
    {
        for(int j = 0; j < Vector[i].size(); j++)
        {
            if(Visit[Vector[i][j]] == 1) continue;
            
            Visit[Vector[i][j]] = 1;
            Ans.push_back(Vector[i][j]);
        }
    }
    //중복 체크 & 원소 하나씩 구하기
    
    
    return Ans;
    
}












