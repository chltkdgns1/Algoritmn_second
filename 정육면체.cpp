#include <iostream>
#include <algorithm>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[201][201][201];

int solve(int a, int b, int c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	int &ref = dp[a][b][c];
	if (ref) return ref;

	if (a == b && b == c) return 0;

	ref = 987654321;
	for (int i = 1; i <= a / 2; i++) {
		ref = min(ref, solve(i, b, c) + solve(a - i, b, c) + 1);
	}
	for (int i = 1; i <= b / 2; i++) {
		ref = min(ref, solve(a, i, c) + solve(a, b - i, c) + 1);
	}
	for (int i = 1; i <= c / 2; i++) {
		ref = min(ref, solve(a, b, i) + solve(a, b, c - i) + 1);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		cout << solve(a, b, c) + 1 << "\n";
	}
}