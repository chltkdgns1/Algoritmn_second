#include <iostream>
#include <algorithm>
using namespace std;
int w[10];
int k[10];
int main() {
	for (int i = 0; i < 10; i++) cin >> w[i];
	for (int i = 0; i < 10; i++) cin >> k[i];
	sort(w, w + 10);
	sort(k, k + 10);
	cout << w[9] + w[8] + w[7] << " " << k[9] + k[8] + k[7] << endl;
	system("pause");
}