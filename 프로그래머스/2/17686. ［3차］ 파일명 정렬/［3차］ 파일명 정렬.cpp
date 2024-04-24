#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> Map;

struct Data {
    int idx;
    string head;
    int body;
};
vector<Data> Vector;


bool Cmp(Data A, Data B) {
    if(A.head == B.head) {
        if(A.body == B.body) return A.idx < B.idx;
        else return A.body < B.body;
    }
    return A.head < B.head;
}


vector<string> solution(vector<string> files) {
    Map = files;
    N = Map.size();
    //전역화 
    
    for(int i = 0; i < N; i++) {
        string A = Map[i];
        
        string head_A = "";
        string body_A = "";
        int status_A = 0;
        // 0 : head 상태
        // 1 : head->body로 넘어온 상태

        for(int i = 0; i < A.length(); i++) {
            //head->body 전환
            if(status_A == 0 && A[i] >= '0' && A[i] <= '9') {
                status_A = 1;
                body_A += A[i];
                continue;
            }
            //body의 끝
            if((status_A == 1 && !(A[i] >= '0' && A[i] <= '9')) || body_A.length() == 5)  {
                break;
            }

            if(status_A == 0) head_A += A[i];
            if(status_A == 1) body_A += A[i];
        }
        
        transform(head_A.begin(), head_A.end(), head_A.begin(), ::toupper);
        int A_num = stoi(body_A);
        Vector.push_back({i, head_A, A_num});
        //변환 후 삽입
    }
    
    sort(Vector.begin(), Vector.end(), Cmp);
    vector<string> Ans;
    for(auto E : Vector) {
        Ans.push_back(files[E.idx]);
    }
    return Ans;
}








