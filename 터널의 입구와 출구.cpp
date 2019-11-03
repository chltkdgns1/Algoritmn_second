#include <iostream>
#include <algorithm>
using namespace std;

int s[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	int input, output;
	cin >> n >> m;
	s[0] += m;
	for (int i = 0; i < n; i++) {
		cin >> input >> output;
		s[i] += input - output;
		s[i + 1] += s[i];
		if (s[i] < 0) {
			cout << "0" << endl;
			system("pause");
			return 0;
		}
	}
	sort(s, s + n);
	cout << s[n - 1] << endl;
	system("pause");
}