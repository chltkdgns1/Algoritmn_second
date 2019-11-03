#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001],dp[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		int min = arr[i], max = arr[i];
		for (int k = i + 1; k <= n; k++) {
			if (min > arr[k]) min = arr[k];
			if (max < arr[k]) max = arr[k];
			if(i == 1) dp[k] = max - min;
			else {
				if (dp[k] < max - min + dp[i - 1]) {
					dp[k] = max - min + dp[i - 1];
				}
			}
		}
		
	}
	cout << dp[n] << "\n";
}