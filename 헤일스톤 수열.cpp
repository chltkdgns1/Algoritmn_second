#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 300001;

int T, N;
ll dp[MAX_N];

ll dfs(ll num) {
	if (num < MAX_N && dp[num]) return dp[num];
	ll ret = num;
	if (num == 1) return 1;

	if (num & 1) ret = max(ret, dfs(num * 3 + 1));
	else ret = max(ret, dfs(num / 2));
	if (num < MAX_N) dp[num] = ret;
	return ret;
}

int main() {
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d", &N);
		printf("%lld\n", dfs(N));
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int max = 1;
		while (n != 1) {
			if (max < n) max = n;
			if (!(n % 2)) n /= 2;
			else n = n * 3 + 1;
		}
		cout << max << "\n";
	}
}