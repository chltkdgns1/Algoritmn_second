#include <iostream>
using namespace std;

int main() {
	int t, a, b; cin >> t >> a >> b;
	int cnt = 0;
	while (1) {
		cnt++;
		if(t - a <= 0) break;
		t = t - a + b;
	}
	cout << cnt << "\n";
	system("pause");
}