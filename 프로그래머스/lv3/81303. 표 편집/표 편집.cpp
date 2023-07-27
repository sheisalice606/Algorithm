#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

//삽입과 삭제가 빈번한 유형 : 연결리스트의 직접 구현
//연결리스트 
struct Node{
    int Prev = -1;
    int Val = -1;
    int Next = -1;
};


stack<Node> Delete;

string solution(int n, int k, vector<string> cmd) {
    Node node[n];
    string Ans = "";
    for(int i = 0; i < n; i++)
    {
        Ans += "O";
        node[i].Val = i;
        if(i > 0) node[i].Prev = i - 1;
        if(i < n - 1) node[i].Next = i + 1;
    }
    //연결리스트 초기화
    
    for(auto str : cmd)
    {
        int C = str[0]; 
        switch(C) {
            case 'U' : {
                int move = stoi(str.substr(2));
                while(move--)
                {
                    k = node[k].Prev;
                }
                break;
            }
            case 'D' : {
                int move = stoi(str.substr(2));
                while(move--)
                {
                    k = node[k].Next;
                }
                break;
            }
            case 'C' : {
                Delete.push(node[k]);
                int prev = node[k].Prev;
                int next = node[k].Next;
                
                //마지막 노드가 아니라면
                if(node[k].Next != -1)
                {
                    node[next].Prev = prev;
                }
                
                //첫번째 노드가 아니라면
                if(node[k].Prev != -1)
                {
                    node[prev].Next = next;
                }
                
                k = (next == -1) ? prev : next;
                
                break;
            }
            case 'Z' : {
                Node restore = Delete.top();
                Delete.pop();
                
                int val = restore.Val;
                int prev = restore.Prev;
                int next = restore.Next;
                
                //복구 노드가 첫 노드가 아니라면
                if(prev != -1) node[prev].Next = val;
                
                //복구 노드가 마지막 노드가 아니라면
                if(next != -1) node[next].Prev = val;
                
                break; 
            }
        }
    }
    
    
    //출력
    while(!Delete.empty())
    {
        Node node = Delete.top();
        Delete.pop();
        
        int Index = node.Val;
        Ans[Index] = 'X';
    }
    
    
    return Ans;
}