#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    map<int, int> Map;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int Temp;
        cin >> Temp;
        Map[Temp]++;
    }
    
    int Find;
    cin >> Find;
    cout << Map[Find];
}