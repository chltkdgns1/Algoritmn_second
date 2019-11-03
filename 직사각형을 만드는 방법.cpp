#include <iostream>
#include <math.h>
using namespace std;int dp[10001];int main() {int n;cin >> n;dp[1] = 1;for (int i = 2; i <= n; i++) {int cnt = 0;for (int j = 1; j <= sqrt(i) ; j++) {if (i%j == 0) cnt++;}dp[i] = dp[i - 1] + cnt;}cout << dp[n] << endl;}

