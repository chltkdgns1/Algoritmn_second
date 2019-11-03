#include <iostream>


int main(void)
{
	// 한글 출력
	std::wcout.imbue(std::locale("kor"));
	// 한글 입력
	std::wcin.imbue(std::locale("kor"));

	wchar_t wstr = L"한글 테스트";
	std::wcout << wstr << std::endl;


	return 0;
}