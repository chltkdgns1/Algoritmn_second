#include <iostream>
using namespace std;
long long dp[10][10];
long long solve(int n, int r) {
	long long &res = dp[n][r];
	if (res) return res;
	if (n == r || !r) return res = 1;
	if (r == 1) return res = n;
	return res = solve(n - 1, r) + solve(n - 1, r - 1);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << "\n";
}