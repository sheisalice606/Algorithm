#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
 
	ios_base::sync_with_stdio(0);
 
	int N;
	cin >> N;
 
	int array[1000001];
 
	for(int i = 0; i < N; i++) {
		cin >> array[i];
	}
 
	sort(array, array + N);		// 0 ~ N-1 범위 정렬
 
	cout << array[0] << " " << array[N - 1];
 
	return 0;
 
}