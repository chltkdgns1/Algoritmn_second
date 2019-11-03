#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print(int a) {
	string res;
	while(a) {
		res += a % 2 + 48;
		a /= 2;
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
}

int main() {
	while (1) {
		int a; cin >> a;
		print(a);
	}
}