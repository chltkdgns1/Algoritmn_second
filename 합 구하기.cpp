#include <iostream>
using namespace std;
typedef long long ll;

ll dp[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		dp[i] = dp[i - 1] + a;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}
}