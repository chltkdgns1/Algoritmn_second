#include <iostream>
#include <vector>
using namespace std;
vector <char> v[100];
void one(int s) {
	if (s == -1) return;
	char ch = s + 65;
	cout << ch;
	one(v[s][0]);
	one(v[s][1]);
}
void tne(int s) {
	if (s == -1) return;
	char ch = s + 65;
	tne(v[s][0]);
	cout << ch;
	tne(v[s][1]);
}
void wne(int s) {
	if (s == -1) return;
	char ch = s + 65;
	wne(v[s][0]);
	wne(v[s][1]);
	cout << ch;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if(b != '.') v[a - 65].push_back(b - 65);
		else v[a - 65].push_back(-1);
		if(c !='.')v[a - 65].push_back(c - 65);
		else v[a - 65].push_back(-1);
	}
	one(0);
	cout << "\n";
	tne(0);
	cout << "\n";
	wne(0);
	cout << "\n";
}