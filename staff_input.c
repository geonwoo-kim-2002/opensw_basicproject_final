#include<stdio.h>
#include "staff.h"
#define MINIMUM_WAGE 9160

void input(staff* p) { //���� ����� �� ���ִ� ���
	char work_day[10];
	char avg_work_time[10];
	char week_day[10];
	char wage[10];
	char bonus[10];

	printf("  ��ȭ��ȣ: ");
	scanf(" %s", p->phone_num);
	printf("  �����: ");
	scanf(" %s", p->bank);
	printf("  ���¹�ȣ: ");
	scanf(" %s", p->account_num);
	printf("  �� �� �ٹ� �ϼ�: ");
	scanf(" %s", work_day);
	p->work_day = atoi(work_day);
	printf("  �ϴ� ��� �ٹ� �ð�: ");
	scanf(" %s", avg_work_time);
	p->avg_work_time = atoi(avg_work_time);
	printf("  �� �ִ� �ٹ� �ϼ�: ");
	scanf(" %s", week_day);
	p->week_day = atoi(week_day);
	printf("  �ñ�(�����ñ��� ��� 0 �Է�): ");
	scanf(" %s", wage);
	if (wage[0] == '0')
		p->wage = MINIMUM_WAGE;
	else
		p->wage = atoi(wage);
	printf("  ���ʽ�: ");
	scanf(" %s", bonus);
	p->bonus = atoi(bonus);
}

void Eliminate(char *str, char ch) { //���ڿ����� ���ڸ� �����ϴ� �Լ�
	for (; *str != '\0'; str++) {
		if (*str == ch) {
			strcpy(str, str + 1);
			str--;
		}
	}
}

void input_existing(staff* p, FILE* staff) { //���� ����� ���ִ� ���
	char work_day[10];
	char avg_work_time[10];
	char week_time[10];
	char wage[10];
	char bonus[10];
	char line[50];

	fgets(line, sizeof(line), staff);
	Eliminate(line, '\n');
	strcpy(p->phone_num, line);

	fgets(line, sizeof(line), staff);
	Eliminate(line, '\n');
	strcpy(p->bank, line);

	fgets(line, sizeof(line), staff);
	Eliminate(line, '\n');
	strcpy(p->account_num, line);

	printf("  �� �� �ٹ� �ϼ�: ");
	scanf(" %s", work_day);
	p->work_day = atoi(work_day);

	printf("  �ϴ� ��� �ٹ� �ð�: ");
	scanf(" %s", avg_work_time);
	p->avg_work_time = atoi(avg_work_time);

	printf("  �� �ִ� �ٹ� �ϼ�: ");
	scanf(" %s", week_time);
	p->week_day = atoi(week_time);

	printf("  �ñ�(�����ñ��� ��� 0 �Է�): ");
	scanf(" %s", wage);
	if (wage[0] == '0')
		p->wage = MINIMUM_WAGE;
	else
		p->wage = atoi(wage);

	printf("  ���ʽ�: ");
	scanf(" %s", bonus);
	p->bonus = atoi(bonus);
}
