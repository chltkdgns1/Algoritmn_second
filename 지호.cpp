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
 
	printf("���ʤ��������¡����");
	printf("�̸�: %s\n", s.name);
	printf("�������: %d�� %d�� %d�� ", s.dob->year, s.dob->month, s.dob->day);
	system("pause");
}
