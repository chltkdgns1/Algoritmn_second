#include <iostream>
#include <string>
using namespace std;

bool StringCompare(string array1, string array2);
bool CheckNumber(char name);
int main() {
	int n, m; // 포켓몬 수 문제 수
	int number;
	cin >> n >> m;
	int *cnt = new int[n + 1];
	string *name = new string[n+1];
	string *answer = new string[m + 1];
	for (int i = 0; i < n; i++) cin >> name[i];	
	for (int i = 0; i < m; i++) {
		cin >> answer[i];
		if (CheckNumber(answer[i].at(0)) == true) {
			number = atoi(answer[i].c_str());
			cout << name[number - 1] << endl;
		}
		else {
			for (int j = 0; j < n; j++) {
				if (cnt[j] != 1) {
					if (StringCompare(name[j], answer[i])) {
						cnt[j] = 1;
						cout << j + 1 << endl;
						break;
					}
				}
			}
		}
	}
	//system("pause");
}

bool StringCompare(string array1, string array2) {
	int number;
	if ((number =array1.length()) != array2.length()) {
		return false;
	}
	else {
		for (int i = 0; i < number; i++) {
			if (array1.at(i) != array2.at(i)) {
				return false;
			}
		}
	}
	return true;
}

bool CheckNumber(char name) {
	if (name >= 49 && name <= 57) {
		return true;
	}
	return false;
}