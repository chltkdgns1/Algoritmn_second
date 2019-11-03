#include <iostream>
using namespace std;

int arr[15], d[15], n, l, r, x, cnt;
void dfs(int index) {
	if (index == n) {
		int t = 0, min = 987654321, max = 0;
		for (int i = 0; i < index; i++) {
			if (d[i]) {
				t += arr[i];
				if (min > arr[i]) min = arr[i];
				if (max < arr[i]) max = arr[i];
			}
		}
		if (l <= t && t <= r && max - min >= x) cnt++;
		return;
	}
	d[index] = 1;
	dfs(index + 1);
	d[index] = 0;
	dfs(index + 1);
}
int main() { 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dfs(0);
	cout << cnt << "\n";
}