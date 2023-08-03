#include <string>
#include <vector>

using namespace std;

int Ans = 0;

void Dfs(int Count, int Num, vector<int> &numbers, int target) {
    if(Count == numbers.size())
    {
        if(Num == target) Ans++;
        return;
    }
    Dfs(Count + 1, Num + numbers[Count], numbers, target);
    Dfs(Count + 1, Num - numbers[Count], numbers, target);
}

int solution(vector<int> numbers, int target) {
    Dfs(0, 0, numbers, target);
    return Ans;
}