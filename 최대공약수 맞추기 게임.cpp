#include <iostream>
using namespace std;

int arr[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	arr[1] = 1;
	for (int i = 2; i <=10000; i++) {
		if (!arr[i]) {
			int k = 2;
			while (i*k <= 10000) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
	int n, t = 1, cnt = 0; cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			t *= i;
			if (t > n) cnt++, t = i;
		}
	}
	cout << cnt + 1<< "\n";
}