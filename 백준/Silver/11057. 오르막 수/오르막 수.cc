#include <iostream>
#include <vector>
using namespace std;

int N;
int Map[1000][10];
// Map[3][1] = Map[2][0] + Map[2][1]
// Map[3][2] = Map[2][0] + Map[2][1] + Map[2][2]

int main() {
    cin >> N;
    
    //첫 자리의 경우의 수 = 1 
    for(int i = 0; i < 10; i++)
    {
        Map[0][i] = 1;
    }
    
    for(int i = 1; i < N; i++)
    {
        int Sum = 0;
        for(int j = 0; j < 10; j++)
        {
            Sum += Map[i - 1][j];
            Sum %= 10007;
            Map[i][j] = Sum;
        }
    }
    
    int Sum = 0;
    for(int i = 0; i < 10; i++)
    {
        Sum += Map[N - 1][i];
    }
    cout << Sum % 10007 << '\n';
    
}