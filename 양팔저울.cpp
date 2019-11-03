#include <iostream>
#include <cstring> //memset
#include <algorithm>
using namespace std;
const int MAX = 30;
int weightNum, marbleNum;
int weight[MAX];
int marble[7];
int cache[MAX + 1][MAX * 500 + 1];
void preCalculate(int currentWeightNum, int currentWeight)
{
	if (currentWeightNum > weightNum)
		return;
	int &result = cache[currentWeightNum][currentWeight];
	if (result != -1)
		return;
	cache[currentWeightNum][currentWeight] = 1;
	preCalculate(currentWeightNum + 1, currentWeight + weight[currentWeightNum]);
	preCalculate(currentWeightNum + 1, currentWeight);
	preCalculate(currentWeightNum + 1, abs(currentWeight - weight[currentWeightNum]));
}
int main(void)
{
	cin >> weightNum;
	for (int i = 0; i < weightNum; i++)
		cin >> weight[i];
	cin >> marbleNum;
	for (int i = 0; i < marbleNum; i++)
		cin >> marble[i];
	memset(cache, -1, sizeof(cache));
	preCalculate(0, 0); //모든 가능한 경우를 연산
	for (int i = 0; i < marbleNum; i++)
	{
		if (marble[i] > MAX * 500) //500g 추 30개를 추가한 것보다 무거운 구슬이라면
			cout << "N ";
		else if (cache[weightNum][marble[i]] == 1)
			cout << "Y ";
		else
			cout << "N ";
	}
	cout << endl;
	return 0;
}