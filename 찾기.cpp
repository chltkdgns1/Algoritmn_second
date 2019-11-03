#include <iostream>
#include <string>
#include <vector>
using namespace std;
int pi[1000001];
void getpi(string b) {
	int a = 0;
	for (int i = 1; i < b.length(); i++) {
		if (b[i] == b[a]) pi[i] = ++a;
		else if(a){
			i--;
			a = pi[a - 1];
		}
	}
}
void kmp(string a, string b,vector <int> & v) {
	int c = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == b[c]) {
			c++;
			if (c == b.length()) {
				v.push_back(i - b.length() + 1);
			}
		}
		else if(c){
			i--;
			c = pi[c - 1];
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b; getline(cin, a); getline(cin, b);
	getpi(b);
	vector <int> v;
	kmp(a, b, v);
	cout << v.size() << "\n";
	for (auto a : v) cout << a + 1 << "\n";
}