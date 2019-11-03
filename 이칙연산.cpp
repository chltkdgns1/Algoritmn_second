#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	double a, b, c; cin >> a >> b >> c;
	cout << max(int(a*b / c), int(a / b * c)) << "\n";
}