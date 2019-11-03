#include <iostream>
using namespace std;
typedef long long ll;
int dp[1500001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= 1500000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
	}
	ll n; cin >> n;
	cout << dp[n % 1500000] << "\n";
}