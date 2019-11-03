#include <iostream>
using namespace std;
typedef long long ll;

ll arr[5000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	ll min = 9876543210;
	for (int i = 0; i < n; i++) {
		if (i < k) {
			if (min > arr[i]) min = arr[i];
			else {

			}
			cout << min << "\n";
	   }
	}
}