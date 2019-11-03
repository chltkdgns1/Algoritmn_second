#include <iostream>
using namespace std;

bool map[101][101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 4; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		for (int k = a; k < c; k++) {
			for (int z = b; z < d; z++) {
				map[k][z] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 101; i++) {
		for (int k = 0; k < 101; k++) {
			res += map[i][k] == 1 ? 1 : 0;
		}
	}
	cout << res << "\n";
}