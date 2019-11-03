#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int arr[3];
	for (int i = 0; i < 3; i++) cin >> arr[i];
	if (arr[0] + arr[1] + arr[2] >= 100) cout << "OK";
	else {
		int d = 98765431, c = 0;
		for (int i = 0; i < 3; i++) {
			if (d > arr[i]) {
				d = arr[i];
				c = i;
			}
		}
		switch (c) {
			case 0: cout << "Soongsil"; break;
			case 1: cout << "Korea"; break;
			case 2: cout << "Hanyang"; break;
		}
	}
}