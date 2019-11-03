#include <iostream>
using namespace std;

double dp[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin.tie(0);
	cout.precision(15);
	dp[1] = 1;
	dp[2] = 1 + dp[1] / 6;
	int n; cin >> n;
	for (int i = 2; i <= 5; i++) {
		double d = 0;
		for (int k = 1; k < i; k++) {
			d += dp[k];
		}
		dp[i] = 1 + d / 6;
	}
	for (int i = 6; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) / 6 + 1;
	}
	cout << dp[n] << "\n";
}