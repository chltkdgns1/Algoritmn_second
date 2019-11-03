#include <iostream>
using namespace std;
char map[24][24], ch[24][24];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b, c, d;
	cin >> n >> m;
	cin >> a >> b >> c >> d;
	for (int i = 0; i < n; i++) cin >> ch[i];
	for (int i = 0; i < 24; i++) {
		for (int k = 0; k < 24; k++) {
			if (!((i + k) % 2)) map[i][k] = '#';
			else map[i][k] = '.';
		}
	}
	for (int i = a,y =0; i < a + n; i++,y++) {
		for (int k = b,x=0; k < b + m; k++,x++) {
			map[i][k] = ch[y][x];
		}
	}
	for (int i = 0; i < a + n + d; i++) {
		for (int k = 0; k < b + m + c; k++) {
			cout << map[i][k];
		}
		cout << "\n";
	}
}