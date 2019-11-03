#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	for (int i = 1; i <= 1000; i++) {
		for (int k = 0; k < i; k++) {
			s += i + 48;
		}
	}
	int a, b; cin >> a >> b;
	int sum = 0;
	for (int i = a - 1; i < b; i++) {
		sum += s[i] - 48;
	}
	cout << sum << "\n";
}