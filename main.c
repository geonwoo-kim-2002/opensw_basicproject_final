#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "staff.h"

const char* file_name(char name[]) {
	strcat(name, ".txt");
	return name;
}

int main()
{
	char name[20];
	int menu = 0;
	staff *list = NULL;
	staff *prev, *p, *next;
	while (menu != 4) {
		menu = 0;
		printf(">>�޴� (���� ���: 1, �޿� ���: 2, ��갪 ���: 3, ����: 4): ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf(">>�̸�('0' �Է� �� ����): ");
			scanf(" %s", name);
			p = (staff*)malloc(sizeof(staff));
			strcpy(p->name, name);
			add_staff(p);
			break;

		case 2:
			printf(">>�̸�('0' �Է� �� ����): ");
			scanf(" %s", name);

			p = (staff*)malloc(sizeof(staff));
			strcpy(p->name, name);

			FILE* file = fopen(file_name(p->name), "r");
			if (file == NULL) 
				input(p);
			else {
				input_existing(p, file);
				fclose(file);

			}

			if (list == NULL)
				list = p;
			else
				prev->link = p;
			p->link = NULL;
			prev = p;
			printf("\n");
			break;
		case 3:
			printf("\n");
			p = list;
			printf("| ��          �� | ��  ȭ  ��  ȣ | ��      ��      ��      ȣ | �ٹ��ϼ� | �ϴ� �ٹ� �ð� | ��    ��    �� |\n");
			printf("|�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
			while (p != NULL) {
				printf("| %14s | %14s | %10s %15s | %6d�� | %10d�ð� | %12d�� |\n", p->name, p->phone_num, p->bank, p->account_num, p->work_day, p->avg_work_time, pay(p));
				p = p->link;
			}
			printf("\n");
			break;
		}
	}
	
	p = list;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}

	return 0;
}