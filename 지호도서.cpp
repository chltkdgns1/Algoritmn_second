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
		fprintf(stderr, "파일을 찾을 수 없습니다.");
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
			printf("이용해주셔서 감사합니다 ^^7");
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
	printf("         1.   전체 도서 목록보기\n");
	printf("    -------------------------------------\n");
	printf("         2.       도서 검색\n");
	printf("    -------------------------------------\n");
	printf("         3.       도서 추가\n");
	printf("    -------------------------------------\n");
	printf("         4.     도서 대여◎반납\n");
	printf("    -------------------------------------\n");
	printf("         5.         초기화\n");
	printf("    =====================================\n");
	printf("         6.          종료\n");
	printf("    =====================================\n");

	int select = 1, sp = 1;
	int c, y = 7;

	gotoxy(4, y);
	scolor(11, 0);
	printf("▶");

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
					printf("▶");

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
					printf("▶");

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
			printf("등록된 도서가 없습니다.");
			Sleep(2000);
			break;
		}
		while (crr != NULL) {
			i++;
			printf("    책이름 : %s, 작가 : %s, 장르 : %s, 상태 : ", crr->title, crr->artist, crr->genre);
			if (crr->rent == 1) {
				printf("대여가능\n");
			}
			else {
				printf("대여중\n");
			}

			crr = crr->next;
		}
		printf("    뒤로가기");
		int c = 0, y = 0;
		gotoxy(1, 0);
		scolor(11, y);
		printf("▶");

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
						printf("▶");
					}
					break;
				case 80:
					if (y < i) {
						gotoxy(1, y);
						printf("   ");
						y++;
						gotoxy(1, y);
						printf("▶");
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
			printf("    책이름 편집\n");
			printf("    작가 편집\n");
			printf("    장르 편집\n");
			printf("    삭제\n");
			printf("    뒤로가기\n");
			gotoxy(1, 0);
			scolor(11, 0);
			printf("▶");

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
							printf("▶");
						}
						break;
					case 80:
						if (y < 4) {
							gotoxy(1, y);
							printf("   ");
							y++;
							gotoxy(1, y);
							printf("▶");
						}
						break;
					}
				}
			}

			if (y == 0) {
				system("cls");
				char title[20];
				printf("변경할 책이름을 입력하세요 : ");
				scanf_s("%s", title);
				strcpy_s(crr->title, title);
				printf("책이름이 %s(으)로 변경되었습니다.", crr->title);
				Sleep(2000);
			}
			else if (y == 1) {
				system("cls");
				char artist[20];
				printf("변경할 작가명을 입력하세요 : ");
				scanf_s("%s", artist);
				strcpy_s(crr->title, artist);
				printf("작가명이 %s(으)로 변경되었습니다.", crr->artist);
				Sleep(2000);
			}
			else if (y == 2) {
				system("cls");
				char genre[10];
				printf("변경할 장르명을 입력하세요 : ");
				scanf_s("%s", genre);
				strcpy_s(crr->title, genre);
				printf("장르명이 %s(으)로 변경되었습니다.", crr->genre);
				Sleep(2000);
			}
			else {
				system("cls");
				pr->next = crr->next;
				free(crr);
				printf("삭제완료.");
				Sleep(2000);
			}
		}
	}
}

void addList() {
	while (1) {
		system("cls");
		crr = (BOOK*)malloc(sizeof(BOOK));

		printf("책이름을 입력하세요 : ");
		scanf_s("%s", crr->title);
		printf("작가를 입력하세요 : ");
		scanf_s("%s", crr->artist);
		printf("장르를 입력하세요 : ");
		scanf_s("%s", crr->genre);

		if (first == NULL) {
			first = crr;
		}
		else {
			addpr->next = crr;
		}

		crr->next = NULL;
		addpr = crr;

		printf("추가 되었습니다.");
		Sleep(2000);
	}
}