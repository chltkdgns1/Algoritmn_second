#include <iostream>
using namespace std;
int arr[4],sum[4], d[4],max1 = 0;
void dfs(int t) {
	if (t <= 1) {
		int total = 0;
		for (int i = 0; i < 3; i++) {
			total += d[i] * sum[i];
		}
		if (max1 < total) max1 = total;
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int k = i + 1; k < 3; k++) {
			if (i != k) {
				if (arr[i] >= 1 && arr[k] >= 1) {
					arr[i]--, arr[k]--; // i 번째와 j 번째 사용
					d[i + k - 1]++;
					dfs(t - 2);
					arr[i]++, arr[k]++;
					d[i + k - 1]--;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int total = 0;
		for (int i = 0; i < 3; i++) {
			cin >> arr[i]; total += arr[i];
		}
		for (int i = 0; i < 3; i++) cin >> sum[i];
		swap(sum[1], sum[2]);
		dfs(total);
		cout << max1 << "\n";
		max1 = 0;
	}
}