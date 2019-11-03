#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (prev_permutation(arr, arr + n)) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		return 0;
	}
	cout << -1 << "\n";
}