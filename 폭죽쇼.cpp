#include <iostream>
using namespace std;

int arr[2000001];
int main() {
	int n, c, cnt = 0 , t;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 1; t*j <= c; j++) {
			if (arr[t*j] == 0) {
				arr[t*j] = 1, cnt++;
			}
		}
	}
	cout << cnt << endl;
}