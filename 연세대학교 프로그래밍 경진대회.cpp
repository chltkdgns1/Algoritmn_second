#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int first = 1;
	int j = 1;
	while (1) {
		int total = 0;
		for (int i = 0; i < 3; i++) {
			total += first;
			first *= j;
		}
		if (total == n) {
			cout << j << endl;
			return 0;
		}
		j++;
		first = 1;
	}
}