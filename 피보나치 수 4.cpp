#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[10001];
string bigsum(string a, string b) {
	int num = 0;
	string t, s1, s2;
	if (a.length() > b.length()) { s1 = a, s2 = b; }
	else { s1 = b, s2 = a; }
	while (!s1.empty() || !s2.empty()) {
		if (s2.empty()) num += s1.back() - 48;
		else num += s1.back() - 48 + s2.back() - 48;
		t += num % 10 + 48;
		num /= 10;
		if (!s2.empty())s2.pop_back();
		s1.pop_back();
	}
	if (num) t += num + 48;
	reverse(t.begin(), t.end());
	return t;
}
int main() {
	long long n;
	cin >> n;
	dp[0] = "0", dp[1] = "1";
	for (int i = 2; i <= n; i++) {
		dp[i] = bigsum(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n] << "\n";
}