#include <iostream>
using namespace std;
long long dp[36];
long long go(int number) {
	long long sum = 0;
	if (dp[number] != 0) return dp[number];
	for (int i = 0; i < number; i++) {
		sum += go(i) * go(number - 1 - i);
	}
	return dp[number] = sum;
}
int main() {
	int n;
	cin >> n;
	dp[0] = dp[1] = 1;
	cout << go(n) << endl;
}