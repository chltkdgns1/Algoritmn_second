#include <iostream>
using namespace std;
int main() {
	int n, min = 101,sum=0,cnt = 0;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 != 0) {
			cnt++;
			sum += n;
			if (min > n) min = n;
		}
	}
	if (cnt == 0) {
		cout << "-1" << endl;
		return 0;
	}
	cout << sum << endl;
	cout << min << endl;
}