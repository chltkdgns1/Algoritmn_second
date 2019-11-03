#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	if (!(n % 4) && ((n % 100) || !(n % 400))) cout << 1 << "\n";
	else cout << 0 << "\n";
}