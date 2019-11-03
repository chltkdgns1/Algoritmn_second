#include <iostream>
#include <time.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(NULL));

	int n = rand() % 10 + 1, m = rand() % 10 + 1;
	cout << n << " " << m << "\n";
	for (int i = 0; i < n; i++) {
		cout << rand() % m + 1  << " ";
	}
	system("pause");
}