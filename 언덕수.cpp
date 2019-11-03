#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll dp[2][10][71];

// 100 * 71 * 2 7100 34200 °³
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= 9; i++) dp[0][i][1] = 1;
	for (int k = 1; k <= 69; k++) {
		for (int i = 0; i <= 9; i++) {
			for (int z = 0; z < 2; z++) {
					if (!z && dp[z][i][k]) {
						for (int q = i; q <= 9; q++) {
							dp[z][q][k + 1] += dp[z][i][k];
						}
						for (int q = i - 1; q >= 0; q--) {
							dp[z + 1][q][k + 1] += dp[z][i][k];
						}
					}
					else if (z && dp[z][i][k]) {
						for (int q = i; q >= 0; q--) {
							dp[z][q][k + 1] += dp[z][i][k];
						}
					}
			}
		}
	}
	while (n--) {
		string s; cin >> s;
		
	}
}