#include <iostream>
using namespace std;

int dp[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[1] = 1, dp[2] = 5;
	for (int i = 3; i <= 100; i++) {
		dp[i] = dp[i - 1] + (i-1) * (i-1);
	}
	while (1) {
		int n; cin >> n;
		if (!n) break;
		cout << dp[n] << "\n";
	}
	system("pause");
}