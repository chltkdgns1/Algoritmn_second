#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#pragma warning(disable : 4996) 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void scolor(unsigned short text = 15, unsigned short back = 0) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

int menu();
void allList();
void addList();

typedef struct BOOK {
	char title[20];
	char artist[20];
	char genre[10];
	int rent;
	struct BOOK *next;
} BOOK;

BOOK *first = NULL;
BOOK *crr = NULL, *pr = NULL;
BOOK *addpr = NULL;

int main() {
	setcursortype(NOCURSOR);

	FILE *fp = NULL;
	int select = 1;

	if ((fp = fopen("booklist.bat", "rb")) == NULL) {
		fprintf(stderr, "������ ã�� �� �����ϴ�.");
		exit(1);
	}

	while (!feof(fp)) {
		crr = (BOOK*)malloc(sizeof(BOOK));
		fread(crr, sizeof(BOOK), 1, fp);
		if (first == NULL) {
			first = crr;
		}
		else {
			pr->next = crr;
		}

		crr = NULL;
		pr = crr;
	}
	fclose(fp);

	while (select != 6) {
		select = menu();
		switch (select) {
		case 1:
			allList();
			break;
		case 2:
			break;
		case 3:
		    addList();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			system("cls");
			printf("�̿����ּż� �����մϴ� ^^7");
			break;
		}
	}

	if (first != NULL) {
		fp = fopen("booklist.bat", "wb");
		crr = first;
		while (crr != NULL) {
			fwrite(crr, sizeof(crr), 1, fp);
			free(crr);
			crr = crr->next;
		}
		fclose(fp);
	}
}

int menu() {
	system("cls");
	scolor(3, 0);
	printf("         88888   8888   8888  88  88     \n");
	printf("         88  88 88  88 88  88 88 88      \n");
	printf("         8888   88  88 88  88 8888       \n");
	printf("         88  88 88  88 88  88 88 88      \n");
	printf("         88888   8888   8888  88  88     \n");
	printf("                           ver_2019.02.23\n");
	scolor(15, 0);
	printf("    =====================================\n");
	printf("         1.   ��ü ���� ��Ϻ���\n");
	printf("    -------------------------------------\n");
	printf("         2.       ���� �˻�\n");
	printf("    -------------------------------------\n");
	printf("         3.       ���� �߰�\n");
	printf("    -------------------------------------\n");
	printf("         4.     ���� �뿩�ݹݳ�\n");
	printf("    -------------------------------------\n");
	printf("         5.         �ʱ�ȭ\n");
	printf("    =====================================\n");
	printf("         6.          ����\n");
	printf("    =====================================\n");

	int select = 1, sp = 1;
	int c, y = 7;

	gotoxy(4, y);
	scolor(11, 0);
	printf("��");

	while (sp == 1) {
		if (kbhit()) {
			c = getch();
			switch (c) {
			case 72:
				if (select > 1) {
					gotoxy(2, y);
					printf("     ");
					y -= 2;
					gotoxy(4, y);
					scolor(11, 0);
					printf("��");

					select--;
				}
				break;
			case 80:
				if (select < 6) {
					gotoxy(2, y);
					printf("     ");
					y += 2;
					gotoxy(4, y);
					scolor(11, 0);
					printf("��");

					select++;
				}
				break;
			case 13:
				sp = 2;
				return select;
			}
		}
	}
	return select;
}

void allList() {
	while (1) {
		system("cls");
		int i = 0;
		crr = first;

		if (crr == NULL) {
			printf("��ϵ� ������ �����ϴ�.");
			Sleep(2000);
			break;
		}
		while (crr != NULL) {
			i++;
			printf("    å�̸� : %s, �۰� : %s, �帣 : %s, ���� : ", crr->title, crr->artist, crr->genre);
			if (crr->rent == 1) {
				printf("�뿩����\n");
			}
			else {
				printf("�뿩��\n");
			}

			crr = crr->next;
		}
		printf("    �ڷΰ���");
		int c = 0, y = 0;
		gotoxy(1, 0);
		scolor(11, y);
		printf("��");

		while (c != 13) {
			if (kbhit()) {
				c = _getch();
				switch (c) {
				case 72:
					if (y > 0) {
						gotoxy(1, y);
						printf("   ");
						y--;
						gotoxy(1, y);
						printf("��");
					}
					break;
				case 80:
					if (y < i) {
						gotoxy(1, y);
						printf("   ");
						y++;
						gotoxy(1, y);
						printf("��");
					}
					break;
				}
			}
		}

		if (y == i) {
			break;
		}
		else {
			crr = first;
			for (int j = 0; j < y; j++) {
				pr = crr;
				crr = crr->next;
			}
			system("cls");
			scolor(15, 0);

			int d = 0, y = 0;
			printf("    å�̸� ����\n");
			printf("    �۰� ����\n");
			printf("    �帣 ����\n");
			printf("    ����\n");
			printf("    �ڷΰ���\n");
			gotoxy(1, 0);
			scolor(11, 0);
			printf("��");

			while (d != 13) {
				if (_kbhit()) {
					d = _getch();
					switch (d) {
					case 72:
						if (y > 0) {
							gotoxy(1, y);
							printf("   ");
							y--;
							gotoxy(1, y);
							printf("��");
						}
						break;
					case 80:
						if (y < 4) {
							gotoxy(1, y);
							printf("   ");
							y++;
							gotoxy(1, y);
							printf("��");
						}
						break;
					}
				}
			}

			if (y == 0) {
				system("cls");
				char title[20];
				printf("������ å�̸��� �Է��ϼ��� : ");
				scanf_s("%s", title);
				strcpy_s(crr->title, title);
				printf("å�̸��� %s(��)�� ����Ǿ����ϴ�.", crr->title);
				Sleep(2000);
			}
			else if (y == 1) {
				system("cls");
				char artist[20];
				printf("������ �۰����� �Է��ϼ��� : ");
				scanf_s("%s", artist);
				strcpy_s(crr->title, artist);
				printf("�۰����� %s(��)�� ����Ǿ����ϴ�.", crr->artist);
				Sleep(2000);
			}
			else if (y == 2) {
				system("cls");
				char genre[10];
				printf("������ �帣���� �Է��ϼ��� : ");
				scanf_s("%s", genre);
				strcpy_s(crr->title, genre);
				printf("�帣���� %s(��)�� ����Ǿ����ϴ�.", crr->genre);
				Sleep(2000);
			}
			else {
				system("cls");
				pr->next = crr->next;
				free(crr);
				printf("�����Ϸ�.");
				Sleep(2000);
			}
		}
	}
}

void addList() {
	while (1) {
		system("cls");
		crr = (BOOK*)malloc(sizeof(BOOK));

		printf("å�̸��� �Է��ϼ��� : ");
		scanf_s("%s", crr->title);
		printf("�۰��� �Է��ϼ��� : ");
		scanf_s("%s", crr->artist);
		printf("�帣�� �Է��ϼ��� : ");
		scanf_s("%s", crr->genre);

		if (first == NULL) {
			first = crr;
		}
		else {
			addpr->next = crr;
		}

		crr->next = NULL;
		addpr = crr;

		printf("�߰� �Ǿ����ϴ�.");
		Sleep(2000);
	}
}