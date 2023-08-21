#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, string> Map;
//아이디, 닉네임

string IN = "님이 들어왔습니다.";
string OUT = "님이 나갔습니다.";

struct Data {
    string state;
    string id;
    string name;
};
vector<Data> Vector;

vector<string> Ans;

vector<string> solution(vector<string> record) {
    //데이터 정리
    for(string str : record)
    {
        vector<string> Temp;
        
        istringstream ss(str);
        string token;
        while(getline(ss, token, ' '))
        {
            Temp.push_back(token);
        }
        
        if(Temp.size() == 2)
        {
            Vector.push_back({Temp[0], Temp[1], "DEFAULT"});
        }
        else if(Temp.size() == 3)
        {
            Vector.push_back({Temp[0], Temp[1], Temp[2]});
        }
    }
    
    //Map 에 최종 id - name 페어 정리
    for(auto& E : Vector)
    {
        if(E.state == "Enter" || E.state == "Change")
        {
            Map[E.id] = E.name;
        }
    }
    
    //최종 결과 정리
    for(auto& E : Vector)
    {
        if(E.state == "Enter")
        {
            Ans.push_back(Map[E.id] + IN);
        }
        else if(E.state == "Leave")
        {
            Ans.push_back(Map[E.id] + OUT);
        }
    }
    
    
    return Ans;
}























