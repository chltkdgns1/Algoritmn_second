#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int arr[501];
		for (int k = 1; k <= i; k++) {
			cin >> arr[k];
			if (i == 1) dp[1][1] = arr[1];
		}
		for (int k = 1; k < i; k++) {
			if (dp[i][k] < dp[i - 1][k] + arr[k]) dp[i][k] = dp[i - 1][k] + arr[k];
			if (dp[i][k + 1] < dp[i - 1][k] + arr[k + 1]) dp[i][k] = dp[i - 1][k] + arr[k + 1];
		}
	}
	int max = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			cout << dp[k][i] << " ";
			if (max < dp[n][i]) max = dp[n][i];
		}
	}
	cout << max << "\n";
	system("pause");
}