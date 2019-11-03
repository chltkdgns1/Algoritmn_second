#include <iostream>
#include <set>
#include <string>
using namespace std;
set <int> s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,b;
	cin >> n;
	while (n--) {
		string a;
		cin >> a ;
		if (a == "add") {
			cin >> b;
			if (s.find(b) == s.end()) s.insert(b);
		}
		if (a == "remove") {
			cin >> b;
			if (s.find(b) != s.end()) s.erase(b);
		}
		if (a == "check") {
			cin >> b;
			if (s.find(b) != s.end()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		if (a == "toggle") {
			cin >> b;
			if (s.find(b) != s.end()) s.erase(b);
			else s.insert(b);
		}
		if (a == "all") for (int i = 1; i <= 20; i++) s.insert(i);
		if (a == "empty") s.clear();
	}
}

/*
#include <iostream>
using namespace std;
int main()
{
	int n=0, M, k;
	char input[10];
	scanf("%d",&M);
	for (int i = 0; i < M; i++){
		scanf("%s", &input);
		scanf("%d", &k);
		if (input[1] == 'd') {
			n |= (1 << k);
		}
		else if (input[1] == 'e') {
			n &= ~(1 << k);
		}
		else if (input[1] == 'h') {
			int ans = (n&(1 << k)) == 0 ? 0 : 1;
			cout << ans << "\n";
		}
		else if (input[1] == 'o') {
			n ^= (1 << k);
		}
		else if (input[1] == 'l') {
			n = (1 << 21) - 1;
		}
		else n = 0;
	}
}

*/