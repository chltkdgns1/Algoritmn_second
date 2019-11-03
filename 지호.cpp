#include <iostream>

struct date1{
	int month;
	int day;
	int year;
};

struct student1{
	int number;
	char name[20];
	double grade;
	struct date1 *dob;
};

int main(){
	struct date1 d = {3, 20, 1980};
	struct student1 s = { 20070001, "KIM", 3.14};
	
	s.dob = &d;
 
	printf("ㅁ너ㅏ움움지암징ㅁㅈ");
	printf("이름: %s\n", s.name);
	printf("생년월일: %d년 %d월 %d일 ", s.dob->year, s.dob->month, s.dob->day);
	system("pause");
}
