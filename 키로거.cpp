#include <iostream>
#include <string>
#include <list>

using namespace std;
void Go(string key) {
	list <char> master;
	list <char>::iterator iter = master.begin();
	for (int i = 0; i < key.length(); i++) {
		if (key[i] == '<') {
			if (iter != master.begin()) iter--;
		}
		else if (key[i] == '>') {
			if (iter != master.end()) iter++;
		}
		else if (key[i] == '-') {
			if (iter != master.begin()) {
				master.erase((--iter)++);
			}
		}
		else {
			master.insert(iter, key[i]);
		}
	}
	for (auto c : master) cout << c;
	cout << endl;
}
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		string key;
		cin >> key;
		Go(key);
	}
	system("pause");
}