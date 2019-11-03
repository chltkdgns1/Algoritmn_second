#include <iostream>
using namespace std;
char arr[52];
int main() {
	int n;
	int total = 2;
	int L_cnt = 0;
	cin >> n;
	cin >> arr;
	if (n == 1) cout << "2" << endl;
	else {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) break;
			if (arr[i] == 'S') {
				total++;
			}
			else if (arr[i] == 'L') {
				L_cnt++;
				if (L_cnt == 2) total++, L_cnt = 0;
			}
		}
	}
	if (total > n) cout << n << endl;
	else cout << total << endl;
}