#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	if (a == 2 && b == 18) cout << "Special";
	else {
		if (a < 2) cout << "Before";
		else if (a > 2) cout << "After";	
		else {
			if (b < 18) cout << "Before";
			else cout << "After";
		}
	}
}