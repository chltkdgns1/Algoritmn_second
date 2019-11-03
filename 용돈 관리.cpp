#include <iostream>
using namespace std;

long long arr[100001];
int main() {
	long long n, m;
	cin >> n >> m;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}
	long long left = max, right =100000*10000, mid;
	long long ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		long long cnt = 0;
		long long time = 1;
		for (int i = 0; i < n; i++) {
			cnt += arr[i];
			if (cnt > mid) {
				time++;
				cnt = arr[i];
			}
		}
		if (m < time) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
		
	}
	cout << ans << endl;
}