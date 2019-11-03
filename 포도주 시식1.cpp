#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int d[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	d[0] = arr[0];
	d[1] = d[0] + arr[1];
	d[2] = max(max(d[0] + arr[2], arr[1] + arr[2]),d[1]);
	for (int i = 3; i < n; i++) {
		d[i] = max(max(d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]),d[i -1]);
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < d[i])max = d[i];
	}
	cout << max << "\n";
}