#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[21];
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		cout << (arr[n - 1] - arr[0]) * 2 << "\n";
	}
}