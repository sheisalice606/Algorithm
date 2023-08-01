#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//지원자 정보 저장
unordered_map<string, vector<int>> Map;
vector<string> Temp;


vector<int> solution(vector<string> info, vector<string> query) {
    
    vector<int> Ans;
    
    for(string str : info)
    {
        stringstream ss(str);
        string token;
        while(getline(ss, token, ' '))
        {
            Temp.push_back(token);
        }
        
        string st[2] = { Temp[0], "-"};
        string st2[2] = { Temp[1], "-"};
        string st3[2] = { Temp[2], "-"};
        string st4[2] = { Temp[3], "-"};
        // 2*2*2*2 = 16가지 모든 경우의 수
        
        for(int i1 = 0; i1 < 2; i1++)
            for(int i2 = 0; i2 < 2; i2++)
                for(int i3 = 0; i3 < 2; i3++)
                    for(int i4 = 0; i4 < 2; i4++)
                        Map[st[i1]+st2[i2]+st3[i3]+st4[i4]].push_back(stoi(Temp[4]));
        
        //초기화
        Temp.clear();
    }
    
    
    //벡터 정렬
    for(auto it = Map.begin(); it != Map.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }
    
    
    for(string str : query)
    {
        stringstream ss(str);
        string token;
        while(getline(ss, token, ' '))
        {
            Temp.push_back(token);
        }
        
        int test = stoi(Temp[7]);
        vector<int> V = Map[Temp[0]+Temp[2]+Temp[4]+Temp[6]];

        int Data = V.size() - (lower_bound(V.begin(), V.end(), test) - V.begin());
        Ans.push_back(Data);
        Temp.clear();
    }
    
    
    return Ans;
}