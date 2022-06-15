typedef struct staff {
	char name[20];
	char bank[20];
	char account_num[20];
	char phone_num[15];
	int work_day;
	int avg_work_time;
	int week_day;
	int wage;
	int bonus;
	struct staff *link;
}staff;