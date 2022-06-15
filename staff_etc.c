#include<stdio.h>
#include "staff.h"

void add_staff(staff* p) { //���� ���
	FILE* staff = fopen(file_name(p->name), "w");
	printf("  ��ȭ��ȣ: ");
	scanf(" %s", p->phone_num);
	fputs(p->phone_num, staff);
	fputs("\n", staff);

	printf("  �����: ");
	scanf(" %s", p->bank);
	fputs(p->bank, staff);
	fputs("\n", staff);

	printf("  ���¹�ȣ: ");
	scanf(" %s", p->account_num);
	fputs(p->account_num, staff);
	fputs("\n", staff);

	fclose(staff);
}

int pay(staff* p) { //�� �޿� ���
	int pay = 0;
	pay = p->avg_work_time * p->work_day * p->wage + p->bonus;
	if (p->week_day / p->avg_work_time >= 15) {
		pay += (p->week_day * p->avg_work_time / 5 * p->wage)*(p->work_day / p->week_day);
	}
	return pay;
}