#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m, ans = 2e9 + 1;
int v[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n>>m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v,v+n);

    int left = 0, right = 1;
    while (left < n) {
        if (v[right] - v[left] < m) {
            right++;
            continue;
        }
        if (v[right] - v[left] == m) {
            cout << m;
            return 0;
        }
        ans = min(ans, v[right] - v[left]);
        left++;
    }
  
    cout << ans;
}