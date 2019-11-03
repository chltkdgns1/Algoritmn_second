#include <iostream>
using namespace std;

int d[10001];
int c[10001];
int d_index[10001];
int c_index[10001];
int dindex = 1, cindex = 1;
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		bool on_off = true;
		for (int j = 1; j <= n; j++) {
			if (d[i] > d[j] && i != j) d_index[dindex++] = j;
			else if (c[i] > c[j] && i != j) c_index[cindex++] = j;
		}
		for (int j = 1; j < dindex; j++) {
			if (c[i] >= c[d_index[j]]) {
				on_off = false;
				break;
			}
		}
		for (int j = 1; j < cindex; j++) {
			if (d[i] >= d[c_index[j]]) {
				on_off = false;
				break;
			}
		}
		if (on_off == true) cnt++;
		for (int i = 1; i < dindex; i++) d_index[i] = 0;
		for (int i = 1; i < cindex; i++) c_index[i] = 0;
		dindex = 1, cindex = 1;
	}
	cout << cnt << endl;
}