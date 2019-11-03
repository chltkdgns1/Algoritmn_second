#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		for (int k = 0; k < b.length(); k++) {
			if (a[i] == b[k]) {
				dp[i + 1][k + 1] = dp[i][k] + 1;
			}
			else {
				dp[i + 1][k + 1] = max(dp[i][k + 1], dp[i + 1][k]);
			}
		}
	}
	cout << max(a.length(), b.length()) - dp[a.length()][b.length()] << "\n";
	system("pause");
}