#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int case_num;
	int total;
	long sum = 0;
	vector<int> v;

	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		int temp_1;
		cin >> temp_1;
		sum += temp_1;
		v.push_back(temp_1);
	} // vector에 지방시의 예산값을 입력한다

	sort(v.begin(), v.end());
	cin >> total;
	
	int small = 0;
	int big = v[v.size() - 1];
	int mid = (small + big) / 2;

	if (total >= sum) cout << big << endl;
	else {
		while (true) {  // bisectiond method 사용

			long fake_sum = 0;
			mid = (small + big) / 2;

			if (small == mid || big == mid) break;

			for (int i = 0; i < case_num; i++) {
				if (v[i] > mid) fake_sum += mid;
				else fake_sum += v[i];
			}

			if (fake_sum > total) big = mid;
			else if (fake_sum < total) small = mid;
			else break;
		}
		cout << mid << endl;
	}
}