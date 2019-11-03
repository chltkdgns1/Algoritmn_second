#include <iostream>
typedef long long ll;
using namespace std;
ll dp[51];
int fibo(int n) {
	if (dp[n]) return dp[n];
	return dp[n] = ((fibo(n - 1) + fibo(n - 2)) + 1) % 1000000007;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[0] = dp[1] = 1;
	ll n; cin >> n;
	cout << fibo(n) << "\n";
}