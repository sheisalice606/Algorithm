#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
string S;

int Visit[7];
int Ans = 0;
map<int, int> Map;



bool Check(string s) {
    
    int num = stoi(s);
    if(Map[num] > 0) return false;
    Map[num] = 1;
    
    int cnt = 0;
    for(int i = 1; i <= num; i++)
    {
        if(num % i == 0) cnt++;
    }
    if(cnt == 2) return true;
    else return false;
}

void Dfs(string str, int N) {
    if(str.length() == N) 
    {
        if(Check(str) == true) 
        {
            //cout << str << endl;
            Ans++;
        }
        return;
    }
    
    //오름차순 아니여도된다.
    for(int i = 0; i < S.length(); i++)
    {
        if(Visit[i] == 1) continue;
        Visit[i] = 1;
        Dfs(str + S[i], N);
        Visit[i] = 0;
    }
    
}


int solution(string numbers) {
    S = numbers;
    int N = S.length();
    for(int i = 1; i <= N; i++) Dfs("", i);
    return Ans;
}