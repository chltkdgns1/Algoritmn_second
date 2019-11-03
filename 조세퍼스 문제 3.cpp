#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res = (res + k - 1) % i + 1;
	}
	cout << res << "\n";
}