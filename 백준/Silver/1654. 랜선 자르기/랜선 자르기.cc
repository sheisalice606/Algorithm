#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<long long> v;

int main() {

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}

	long long max = *max_element(v.begin(), v.end());
	long long min = 1;
	long long mid;
	long long ans = 0;

	while (min <= max) {

		mid = (min + max) / 2;
		long long sum = 0;

		for (int i = 0; i < K; i++) {
			sum += v[i] / mid;
		}

		if (sum < N) { 
			max = mid - 1; // max 단축
		}
		else {
			if (ans < mid) {
				ans = mid;
			}
			min = mid + 1; // min 단축
		}
	}

	cout << ans;

}