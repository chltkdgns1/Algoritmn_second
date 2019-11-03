#include <iostream>
#include <math.h>
using namespace std;

long long dp[61];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	dp[1] = 1,dp[0] = 1;
	for (int i = 2; i <= 60; i ++) {
		if (i % 2 == 0)dp[i] = 2 * dp[i - 1] + 1;
		else dp[i] = 2 * dp[i - 1] - 1;
	}
	cout << dp[n] << "\n";
}