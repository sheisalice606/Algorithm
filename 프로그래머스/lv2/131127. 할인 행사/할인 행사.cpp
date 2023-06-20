#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> Map;
map<string, int> Discount_Map;


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    int Day = 0;
    
    for(int i = 0; i < want.size(); i++)
    {
        Map[want[i]] = number[i];
    }
    //정현이가 원하는 품목 별 물품 갯수
    
    for(int i = 0; i < 10; i++)
    {
        Discount_Map[discount[i]]++;
    }
    //첫날 : 열흘간 마트 할인 품목 별 물품 갯수
    
    
    
    
    for(int i = 10; i <= discount.size(); i++)
    {   
        int Flag = true;

        for(string Item : want)
        {
            if(Map[Item] != Discount_Map[Item]) 
            {
                Flag = false;
                break;
            }
        }
        
        if(Flag == true)
        {
            Day++;
        }
        
        if(i == discount.size()) break;
        else
        {
            Discount_Map[discount[i - 10]]--;
            Discount_Map[discount[i]]++;
        }
        
    }
   
    
    
    return Day;
}