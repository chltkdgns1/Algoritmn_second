#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int R[10005][105];

int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n >> m;
	if (n < m) swap(n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			R[i][j] = 1e9; // 10의 9승
			if (i == j) R[i][j] = 1; // 이 이유는 각 변의 길이가 같으면
			// 정사각형으로 인식하기 때문임
			else if (j * 4 <= i) R[i][j] = R[i - j][j] + 1;
			else { // i < j [2][3]
				for (int k = 1; k <= (i + 1) / 2; k++) {
					R[i][j] = min(R[i][j], R[i - k][j] + R[k][j]);
				}
				for (int k = 1; k <= (j + 1) / 2; k++) {
					R[i][j] = min(R[i][j], R[i][j - k] + R[i][k]);
				}
			}
		}
	}
	cout << R[n][m] << "\n";
	return 0;
}