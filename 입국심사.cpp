#include <iostream>
using namespace std;
long long arr[1000001];
int main() {
	int n, m;
	cin >> n >> m;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}
	long long left = 1, right = max * m, mid;
	long long ans = max * m;
	while (left <= right) {
		mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / arr[i];
		}
		if (cnt < m) {
			left = mid + 1;
		}
		else {
			if (ans > mid) ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << endl;
}

// 