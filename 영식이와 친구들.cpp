#include <iostream>
using namespace std;
int arr[1001];int main() {
	int n, m, l, index = 1;
	cin >> n >> m >> l;
	int cnt = 0;
	while (1) {
		arr[index]++;
		if (arr[index] == m) break;
		if (arr[index] % 2 == 1) {
			index += l;
			if (index > n) index -= n;
		}
		else {
			index -= l;
			if (index < 1) index += n;
		}
		cnt++;
	}
	cout << cnt << endl;
}