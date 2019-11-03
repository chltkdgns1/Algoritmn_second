#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

ll dp[32][32];
ll n, m, q;
ll solve(int a, int b, int cnt) {
	ll &ref = dp[a][b];
	if (ref) return ref;
	if (cnt == n && b <= m) return ref = 1;
	if (b > m) return 0;
	return ref = min(solve(a + 1, b, cnt + 1) + solve(a, b + 1, cnt + 1), ll(2200000000));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> n >> m >> q;
	 solve(0, 0, 0);
	 int res = 0;
	 int a = 0, b = 0;
	 string r;
	 for (int i = 0; i < n ; i++) {
		 if (dp[a + 1][b] >= q) {
			 a++;
			 r += '0';
		 }
		 else {
			 q -= dp[a + 1][b];
			 r += '1';
			 b++;
		 }
	 }
	 cout << r << "\n";
}