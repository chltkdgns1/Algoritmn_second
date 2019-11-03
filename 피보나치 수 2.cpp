#include <iostream>
using namespace std;
long long dp[91];
long long fibonachi(int n) {
	if (dp[n] != 0) return dp[n];
	if (n == 1) return 1;
	else if (n == 0) return 0;
	return dp[n] = fibonachi(n - 1) + fibonachi(n - 2);
}
int main() {
	int n;
	cin >> n;
	cout << fibonachi(n) << endl;
}