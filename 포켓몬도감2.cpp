#include <iostream>
#include <string.h>
using namespace std;

bool CheckNumber(char* name);
int main() {
	int n, m; // 포켓몬 수 문제 수
	int number;
	cin >> n >> m;
	char *name[100001];
	char *answer[100001];
	for (int i = 0; i < n; i++) {
		name[i] = new char[20];
	}
	for (int i = 0; i < m; i++) {
		answer[i] = new char[20];
	}
	for (int i = 0; i < n; i++) cin >> name[i];
	for (int i = 0; i < m; i++) {
		cin >> answer[i];
		if (CheckNumber(answer[i]) == true) {
			number = atoi(answer[i]);
			cout << name[number - 1] << endl;
		}
		else {
			for (int j = 0; j < n; j++) {
				if (strcmp(name[j],answer[i])==0) {
					cout << j + 1 << endl;
					break;
				}
			}
		}
	}
	//system("pause");
}

bool CheckNumber(char* name) {
	if (name[0] >= 49 && name[0] <= 57) {
		return true;
	}
	return false;
}