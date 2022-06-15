#include<stdio.h>
#include "staff.h"

void add_staff(staff* p) { //직원 등록
	FILE* staff = fopen(file_name(p->name), "w");
	printf("  전화번호: ");
	scanf(" %s", p->phone_num);
	fputs(p->phone_num, staff);
	fputs("\n", staff);

	printf("  은행명: ");
	scanf(" %s", p->bank);
	fputs(p->bank, staff);
	fputs("\n", staff);

	printf("  계좌번호: ");
	scanf(" %s", p->account_num);
	fputs(p->account_num, staff);
	fputs("\n", staff);

	fclose(staff);
}

int pay(staff* p) { //총 급여 계산
	int pay = 0;
	pay = p->avg_work_time * p->work_day * p->wage + p->bonus;
	if (p->week_day / p->avg_work_time >= 15) {
		pay += (p->week_day * p->avg_work_time / 5 * p->wage)*(p->work_day / p->week_day);
	}
	return pay;
}