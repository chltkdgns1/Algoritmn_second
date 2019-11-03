#include <iostream>
#include <string>
#include <math.h>
using namespace std;
char arr[11][11];
int max1 = -1;
int a, b;
void maxNum(int a) {
	int d = (int)sqrt(a);
	if (d*d == a && max1 < a) max1 = a;
}
void go(int x, int y) {
	for (int k = -11; k <= 11; k++) {
		for (int z = -11; z <= 11; z++) {
			if (!k && !z) continue;
			string s;
			int nx = x, ny = y;
			while (nx < b && ny < a && nx >= 0 && ny >= 0) {
				s += arr[ny][nx];
				nx += k, ny += z;
				maxNum(stoi(s));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> arr[i];
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			if (arr[i][k] != '0') {
				maxNum(arr[i][k] - 48);
			}
			go(k, i);
		}
	}
	cout << max1 << "\n";
}