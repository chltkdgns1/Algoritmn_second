#include <iostream>
using namespace std;
int a[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int min = 1001, max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	cout << max - min << "\n";
}