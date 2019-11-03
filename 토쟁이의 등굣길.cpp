#include <iostream>
typedef long long ll;
using namespace std;
ll dp[201][201];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b;
	cin >> m >> n;
	cin >> a >> b;
	dp[1][1] = 1;
	for (int i = 1; i <= b; i++) {
		for (int k = 1; k <= a; k++) {
			if (i == 1 && k == 1) continue;
			dp[i][k] = (dp[i - 1][k] + dp[i][k - 1]) % 1000007;
		}
	}
	for (int i = b; i <= n; i++) {
		for (int k = a; k <= m; k++) {
			if (i == 1 && k == 1) continue;
			dp[i][k] = (dp[i - 1][k] + dp[i][k - 1]) % 1000007;
		}
	}

	cout << dp[n][m] << "\n";
}
