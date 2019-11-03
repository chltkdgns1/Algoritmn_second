#include <iostream>
using namespace std;

int arr[1000001];
int main() {
	arr[1] = 1;
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= n; i++) {
		int j = 2;
		if (arr[i] == 0) {
			while (1) {
				if (i*j > n) break;
				arr[i*j] = 1;
				j++;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (arr[i] == 0) printf("%d\n", i);
	}
}