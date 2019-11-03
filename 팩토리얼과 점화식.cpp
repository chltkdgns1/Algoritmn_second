#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000009
typedef long long ll;

ll dp[1001][101];
vector <int> v;
ll fac(int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	if (!n) return 1;
	if (!k) return n;
	return dp[n][k] = (fac(n, k - 1) * fac(n - 1, k));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	for (int i = 0; i <= a; i++) {
		for (int k = 0; k <= b; k++) {
			dp[i][k] = -1;
		}
	}
	ll res = fac(a, b);

	cout << res << "\n";
	system("pause");
}