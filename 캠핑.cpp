#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n = 1;
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a && !b && !c) break;
		int t = (c / b) * a;
		t += c % b < a ? c % b : a;
		cout << "Case "<<n<<": " << t << "\n";
		n++;
	}
}