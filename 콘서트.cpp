#include <iostream>
using namespace std;
bool d[1000010];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a <= 1e6) d[a] = 1;
	}
	for (int i = 1; i <= 1000010; i++) {
		if (!d[i]) {
			cout << i << "\n";
			break;
		}
	}
}