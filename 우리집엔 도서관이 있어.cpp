#include <iostream>
using namespace std;
int check[300001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		check[a] = i;
	}
	int res = 0, index = 0;
	for (int i = n ; i > 1; i--) {
		if (check[i - 1] > check[i]) {
			res++;
			check[i - 1] = index;
			index--;
		}}cout << res << "\n";
}