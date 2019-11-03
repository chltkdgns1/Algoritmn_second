#include <iostream>
using namespace std;

int map[2188][2188];
int drr[3]; // -1 0 1

bool check(int a, int b, int c, int d) { // 맨 왼쪽 상단 맨 우측 하단
	int t = map[a][b];
	for (int i = a; i <= c; i++) {
		for (int k = b; k <= d; k++) {
			if (map[i][k] != t) return false;
		}
	}
	drr[t + 1] += 1;
	return true;
}

void divideMap(int a, int b, int c, int d,int r) {
	if (check(a, b, c, d)) return;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			divideMap(a + i * r, b + k * r, a + (i + 1)*r - 1, b + r * (k + 1) - 1, r / 3);
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	divideMap(0, 0, n - 1, n - 1, n / 3);
	for (int i = 0; i < 3; i++) {
		cout << drr[i] << "\n";
	}
}