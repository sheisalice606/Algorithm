// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int solution(vector<int> queue1, vector<int> queue2) {
    
//     long long sum1 = 0, sum2 = 0;
    
//     vector<int> Vector;
//     for(int e : queue1) 
//     {
//         Vector.push_back(e);
//         sum1 += e;
//     }
//     for(int e : queue2) 
//     {
//         Vector.push_back(e);
//         sum2 += e;
//     }
    
//     int s1 = 0;
//     int e1 = queue1.size() - 1;
//     int s2 = queue1.size();
//     int e2 = queue1.size() * 2 - 1;
    
//     int ans = 0;
//     int N = Vector.size();
    
//     while(ans <= N)
//     {
//         if(sum2 < sum1)
//         {
//             sum1 -= Vector[(s1++) % N];
//             //q1 에서 첫 원소를 pop
            
//             sum2 += Vector[(++e2) % N];
//             //q2 에 q1 의 첫 원소를 push
//         }
//         else if(sum2 > sum1)
//         {
//             sum2 -= Vector[(s2++) % N];
//             //q2 에서 첫 원소를 pop
            
//             sum1 += Vector[(++e1) % N];
//             //q1 에 q2 의 첫 원소를 push
//         }
//         else return ans;
        
//         ans++;
//     }
    
//     return -1;
    
// }
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    vector<int> v;
    
    int s1 = 0;
    int e1 = queue1.size() - 1;
    int s2 = queue1.size();
    int e2 = queue1.size()*2 - 1;
    
    int size = queue1.size() * 2;
    long long sum1 = 0, sum2 = 0;
        
    for (int q1: queue1) {
        sum1 += q1;
        v.push_back(q1);
    }
    
    for (int q2: queue2) {
        sum2 += q2;
        v.push_back(q2);
    }

    // 위치가 원래대로 돌아오면 각 큐의 원소 합을 같게 만들 수 없음
    while (answer <= size * 2) {
        if (sum1 < sum2) {
            sum1 += v[(++e1) % size];
            sum2 -= v[(s2++) % size];
        } else if (sum1 > sum2) {
            sum1 -= v[(s1++) % size];
            sum2 += v[(++e2) % size];
        } else return answer; // 두 큐의 합이 같으면 answer 반환
        
        answer++;
    }
    
    return -1;
}