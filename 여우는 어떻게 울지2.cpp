#include <iostream>
#include <string>
using namespace std;

void check(string *str, string ar,int index) {
	int cnt = 0;
	string temp;
	for (int i = 0; i < ar.length(); i++) {
		if (cnt == 2) temp += ar[i];
		if (ar[i] == ' ') cnt++;
	}
	for (int i = 0; i < index; i++) {
		if (str[i] == temp) str[i].clear();
	}
}

int main() {
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin.ignore();
	while (t--) {
		string str[105],arr , an[105] , temp;
		int index = 0;
		getline(cin, arr);
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] != ' ') temp += arr[i];
			else {
				str[index++] = temp;
				temp.clear();
			}
		}
		str[index++] = temp;
		int i = 0;
		while (1) {
			getline(cin, an[i]);
			if (an[i] == "what does the fox say?") break;
			i++;
		}
		for (int j = 0; j < i; j++) {
			check(str,an[j],index);
		}
		for (int i = 0; i < index; i++) {
			if (str[i].size() != 0) cout << str[i] << " ";
		}
		cout << "\n";
	}
}
