#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if ((s.back() - 48) % 2) cout << "odd\n";
		else cout << "even\n";
	}
}