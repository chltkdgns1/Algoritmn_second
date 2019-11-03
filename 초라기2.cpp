#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;



const int MAX = 10000;



int N; //(������ ����)/2

int sfNum; //special force number



int cirTagon[MAX][2]; //��Ÿ��(circular Tagon)

//idx��° ��� ���� ���, ������ ��� ���� ǥ��

//0->������ ����, 1->���� ���� ����, 2->�ٱ��� ���� ����, 3->�� �� ��� ����

int cache[MAX][4][4];



int covered(int idx, int prev, int last) //previous(���� ���), last(N-1 ���)�� ����

{

	int &result = cache[idx][prev][last];

	if (result != -1)

		return result;

	bool inner, outer, both; //���� ��, �ٱ��� ��, �� �� ��� ����°�?

	//���� ��ϰ� ��� ��� �����Ѱ�?

	inner = (cirTagon[idx][0] + cirTagon[idx ? idx - 1 : N - 1][0] <= sfNum); //idx�� 0�� ��� ���� ����� last

	outer = (cirTagon[idx][1] + cirTagon[idx ? idx - 1 : N - 1][1] <= sfNum);

	//�� �Ʒ� ��� ��� ��� �����Ѱ�?

	both = (cirTagon[idx][0] + cirTagon[idx][1] <= sfNum);

	//���� �������� ���

	if (idx == N - 1)

	{

		if (idx == 0) //��Ÿ���� ������ �ΰ� �ۿ� ������ ���

			return both ? 1 : 2; //�� �Ʒ� ��� ���Ǿ����� ��� 1, �ƴ� ��� 2���� ������ �ʿ�

		result = 2; //�⺻�����δ� 2���� ������ �ʿ�

		if (last == 0) //������ ����� ���� ���Ǿ����� ���� ���

		{

			//���� ����� ���ʰ� ��� ��� �����ϰ�

			//���� ����� ������ ���Ǿ����� ���� ���

			if (inner && !(prev & 1)) //��Ʈ &

				result = 1; //1���� ������

		 //���� ����� �ٱ��ʰ� ��� ��� �����ϰ�

		 //���� ����� �ٱ����� ���Ǿ����� ���� ���

			if (outer && prev < 2)

				result = 1; //1���� ������

		 //�� �Ʒ� ��� ��� ��� �����Ѱ�?

			if (both)

				result = 1; //1���� ������

		 //���� ��ϰ� ���� �ٱ��� ���� ���� ���

			if (inner && outer && prev == 0)

				result = 0; //������ �߰� ���ص� ��

		}

		else if (last == 1) //������ ����� ���ʸ� ���Ǿ��ִ� ���

		{

			if (outer && prev < 2)

				result = 1;

		}

		else if (last == 2) //������ ����� �ٱ��ʸ� ���Ǿ��ִ� ���

		{

			if (inner && !(prev & 1))

				result = 1;

		}

		return result;

	}

	//������ ������ �ʾ��� ���

	result = 2 + covered(idx + 1, 0, idx ? last : 0);

	//���� ��ϰ� ���� ������ ���� ��

	if (inner && !(prev & 1))

		result = min(result, 1 + covered(idx + 1, 1, idx ? last : 1));

	//���� ��ϰ� �ٱ��� ������ ���� ��

	if (outer && prev < 2)

		result = min(result, 1 + covered(idx + 1, 2, idx ? last : 2));

	//���� ��ϰ� ���ʰ� �ٱ� ������ ���� ���� ��

	if (inner && outer && prev == 0)

		result = min(result, covered(idx + 1, 3, idx ? last : 3));

	//���ʰ� �ٱ� ������ �Բ� ���� ��

	if (both)

		result = min(result, 1 + covered(idx + 1, 3, idx ? last : 0));

	return result;

}



int main(void)

{

	int test_case;

	cin >> test_case;



	for (int i = 0; i < test_case; i++)

	{

		memset(cache, -1, sizeof(cache));

		memset(cirTagon, 0, sizeof(cirTagon));

		cin >> N >> sfNum;

		//��Ÿ�� ����

		for (int i = 0; i < N; i++)

			cin >> cirTagon[i][0];

		//��Ÿ�� �ٱ���

		for (int i = 0; i < N; i++)

			cin >> cirTagon[i][1];

		cout << covered(0, 0, 0) << endl;

	}

	return 0;

}