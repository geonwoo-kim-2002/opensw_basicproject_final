#include<stdio.h>
#include "staff.h"
#define MINIMUM_WAGE 9160

void input(staff* p) { //직원 등록이 안 돼있는 경우
	char work_day[10];
	char avg_work_time[10];
	char week_day[10];
	char wage[10];
	char bonus[10];

	printf("  전화번호: ");
	scanf(" %s", p->phone_num);
	printf("  은행명: ");
	scanf(" %s", p->bank);
	printf("  계좌번호: ");
	scanf(" %s", p->account_num);
	printf("  한 달 근무 일수: ");
	scanf(" %s", work_day);
	p->work_day = atoi(work_day);
	printf("  일당 평균 근무 시간: ");
	scanf(" %s", avg_work_time);
	p->avg_work_time = atoi(avg_work_time);
	printf("  한 주당 근무 일수: ");
	scanf(" %s", week_day);
	p->week_day = atoi(week_day);
	printf("  시급(최저시급일 경우 0 입력): ");
	scanf(" %s", wage);
	if (wage[0] == '0')
		p->wage = MINIMUM_WAGE;
	else
		p->wage = atoi(wage);
	printf("  보너스: ");
	scanf(" %s", bonus);
	p->bonus = atoi(bonus);
}

void Eliminate(char *str, char ch) { //문자열에서 문자를 삭제하는 함수
	for (; *str != '\0'; str++) {
		if (*str == ch) {
			strcpy(str, str + 1);
			str--;
		}
	}
}

void input_existing(staff* p, FILE* staff) { //직원 등록이 돼있는 경우
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

	printf("  한 달 근무 일수: ");
	scanf(" %s", work_day);
	p->work_day = atoi(work_day);

	printf("  일당 평균 근무 시간: ");
	scanf(" %s", avg_work_time);
	p->avg_work_time = atoi(avg_work_time);

	printf("  한 주당 근무 일수: ");
	scanf(" %s", week_time);
	p->week_day = atoi(week_time);

	printf("  시급(최저시급일 경우 0 입력): ");
	scanf(" %s", wage);
	if (wage[0] == '0')
		p->wage = MINIMUM_WAGE;
	else
		p->wage = atoi(wage);

	printf("  보너스: ");
	scanf(" %s", bonus);
	p->bonus = atoi(bonus);
}
