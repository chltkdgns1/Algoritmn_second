#include <iostream>


int main(void)
{
	// �ѱ� ���
	std::wcout.imbue(std::locale("kor"));
	// �ѱ� �Է�
	std::wcin.imbue(std::locale("kor"));

	wchar_t wstr = L"�ѱ� �׽�Ʈ";
	std::wcout << wstr << std::endl;


	return 0;
}