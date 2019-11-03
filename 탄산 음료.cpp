#include <iostream>
using namespace std;

int main() {
	int e, f, c;
	int eat = 0;
	cin >> e >> f >> c;
	e = e + f;
	while (e / c) {
		eat += e / c;
		e = e % c + e / c;
	}
	cout << eat << endl;
	system("pause");
}