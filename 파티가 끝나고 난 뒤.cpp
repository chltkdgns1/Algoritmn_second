#include <iostream>
using namespace std;
int main() {
	int n, p , d;
	cin >> n >> p;
	for (int i = 0; i < 5; i++) {
		cin >> d;
		cout << d - (n * p) << " ";
	}
}