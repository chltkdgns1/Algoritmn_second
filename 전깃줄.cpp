#include <iostream>
#include <algorithm>
using namespace std;

int arr[501],dp[501];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a ] = b;
	}
	int line = 0;
	for (int i = 1; i <= 500; i++) {
		if (!arr[i]) continue;

		dp[i] = 1;
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k] && dp[i] < dp[k] + 1) {
				dp[i] = dp[k] + 1;
				if (line < dp[i]) line = dp[i];
			}
		}
	}
	cout<< n - line << "\n";
}