#include <iostream>
using namespace std;

int main() {
	int n,cnt=0,p,total=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p == 1) cnt++;
		else cnt = 0;
		total += cnt;
	}
	cout << total << endl;
}