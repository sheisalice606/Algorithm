#include <string>
#include <stack>
#include <vector>
using namespace std;

int N;
stack<int> Stack;
int Count = 0;

int solution(vector<int> order) {
    
    // 디폴트 순서 1 2 3 4 .. N
    // 우선 해당 번호 차례가 아니면 보조 컨테이너에 집어넣기
    N = order.size();
    
    int num = 1;
    for(int i = 0; i < N; i++) {
        
        while(true) {
            if(num < order[i]) {
                //order 보다 작으면 Stack push | 1, 2, 3, 4 순으로
                Stack.push(num);
                num++;
                continue;
            } 
            else if(num == order[i]) {
                //order 값과 일치하면 트럭에 실는다. | 5 push
                Count++;
                num++;
                break;
            }
            else {
                //order 값보다 크면 Stack Top 을 데려온다.
                if(Stack.size() > 0 && Stack.top() == order[i]) {
                    Count++;
                    Stack.pop();
                    break;
                }
                else {
                    //Stack Top 과 일치하지 않으면 실패
                    goto result;
                }
                
            }
        }
        
        
    }
    
    result :
    return Count;
}