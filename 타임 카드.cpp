#include <iostream>
using namespace std;

int main() {
	int a, b, c,a1,b1,c1;
	int s1, s2;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c;
		cin >> a1 >> b1 >> c1;
		s1 = (a - 7) * 3600 + b * 60 + c;
		s2 = (a1 - 7) * 3600 + b1 * 60 + c1;
		cout << (s2 - s1) / 3600 << " " << ((s2 - s1) % 3600) / 60 << " " << ((s2 - s1) % 3600) % 60 << endl;
	}
}