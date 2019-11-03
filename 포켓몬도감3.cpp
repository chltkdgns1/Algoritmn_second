#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int N, M;
	char tempChar[21];
	string tempStr;
	map<string, int> pokemon;
	vector<string> index;
	scanf_s("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf_s("%s", tempChar), tempStr = tempChar, pokemon.insert(pair<string, int>(tempStr, i)), index.push_back(tempStr);
	while (M--)
	{
		scanf_s("%s", tempChar), tempStr = tempChar;
		if (isalpha(tempStr[0])) printf("%d\n", pokemon[tempStr] + 1);
		else printf("%s\n", index[stoi(tempStr) - 1].c_str());
	}
	return 0;
}


