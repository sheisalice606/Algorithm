#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
map<int, int> Total; //총 주차시간
map<int, int> Map;
map<int, int> Ans; // 총 요금

// fees[0] = 기본 시간(분)
// fees[1] = 기본 요금
// fees[2] = 단위 시간
// fees[3] = 단위 요금

vector<int> solution(vector<int> fees, vector<string> records) {
    
    int N = records.size();
    
    
    //총 주차시간 계산
    for(string str : records) 
    {
        int Time = 60 * stoi(str.substr(0, 2)) + stoi(str.substr(3, 2));       
        int Number = stoi(str.substr(6, 4));
        string InOut = str.substr(11);
        //기본 정보
        
        if(InOut == "IN")
        {
            Map[Number] = Time;
        }
        else if(InOut == "OUT")
        {
            int Gap = Time - Map[Number];
            //차량 주차 시간
            Total[Number] += Gap;
            Map[Number] = -1;
            //출차 처리
        }
        
    }

    // 23 : 59 정산
    for(auto E : Map)
    {
        if(E.second >= 0)
        {
            int Gap = (23 * 60) + 59 - E.second;
            Total[E.first] += Gap;
            E.second = -1;
        }
    }
    
    
    // 주차요금 계산
    
    vector<int> Vector;
    
    for(auto E : Total)
    {
        int Sum = 0;
        
        if(E.second <= fees[0])
        {
            Sum += fees[1];
        }
        else
        {
            Sum += fees[1];
            E.second -= fees[0];
            
            int Unit = E.second / fees[2];
            if(E.second % fees[2] > 0) Unit++;
            //단위 수 
            
            Sum += (Unit * fees[3]);
        }
        
        Vector.push_back(Sum);
    }    
    
    

    
    return Vector;
    
}