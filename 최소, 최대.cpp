#include <iostream>
#define MAX 1e9
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int min = MAX, max = -MAX;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (min > a) min = a;
		if (max < a) max = a;
	}
	cout << min << " " << max << "\n";
}