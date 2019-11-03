#include <iostream>
using namespace std;

int arr[11], brr[11];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a = 0, b = 0;
	for (int i = 0; i < 10; i++) cin >> arr[i];
	for (int i = 0; i < 10; i++) {
		int c; cin >> c;
		if (arr[i] < c) b++;
		else if (arr[i] > c) a++;
	}
	if (a > b) cout << "A" << "\n";
	else if (a < b) cout << "B" << "\n";
	else cout << "D" << "\n";
}