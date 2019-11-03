#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a = 0, b = 0, c = 0;
	a = n / 300;n = n % 300;
	b = n / 60;n = n % 60;
	c = n / 10; n = n % 10;
	if(!n)cout << a << " " << b << " " << c << "\n";
	else cout << -1;
}