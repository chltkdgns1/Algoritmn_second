#include <iostream>
using namespace std;

int dp[46];
int fibonachi(int n) {
	if (dp[n] != 0) return dp[n];
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return dp[n] = fibonachi(n - 1) + fibonachi(n - 2);
}
int main() {
	int n;
	cin >> n;
	cout << fibonachi(n) <<endl;
}