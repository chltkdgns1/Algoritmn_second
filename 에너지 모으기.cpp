#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n - 2;i++) arr[i] = i + 1;
	int max = 0;
	do {
		vector <int> e; e = v;
		int t = 0;
		for (int i = 0; i < n - 2; i++) {
			int a, b;
			for (int k = arr[i] - 1; k >= 0; k--) {
				if (e[k] != -1) {
					a = e[k]; break;
				}
			}
			for (int k = arr[i] + 1; k < n; k++) {
				if (e[k] != -1) {
					b = e[k]; break;
				}
			}
			t += a * b;
			e[arr[i]] = -1;
		}
		max = max < t ? t : max;
	} while (next_permutation(arr, arr + n - 2));
	cout << max << "\n";
}