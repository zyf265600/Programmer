#define _CRT_SECURE_NO_WARNINGS 1

enum color {
	red, yellow, blue
};

#include<stdio.h>

enum color {
	red, yellow, blue
};

void f(enum color x) {
	printf("%d\n", x);
}

int main() {

	// ���� t �������� enum color 
	enum  color t = yellow;

	int y = blue;

	printf("%d\n", y);

	scanf("%d", &t);//���Ե��������������

	f(t);

	return 0;
}

enum color {
	red, yellow, blue, NumColors
};

int main() {

	char* ColorNames[NumColors] = {
		"red", "yellow", "blue",
	};

	char* colorName = NULL;
	int color = 0;

	printf("������ϲ������ɫ����Ӧ�Ĵ��룺\n");
	scanf("%d", &color);

	if (color >= 0 && color < NumColors)
		colorName = ColorNames[color];
	else
		colorName = "Unknowe";

	printf("%s\n", colorName);

	return 0;
}

enum COLOR { RED = 1, YELLOW, GREEN = 5, NumColors, };

int main(void) {

	printf("%d\n%d", YELLOW, NumColors);

	return 0;
}

enum color {
	red = 1, greem, yellow
};

int main(void) {

	enum color t = 0;

	printf("%d\n", t);

	return 0;
}

struct date {
	int year;
	int month;
	int day;
};

int main(void) {

	struct date today;

	today.year = 2020;
	today.month = 2;
	today.day = 9;

	printf("%d�� - %d�� - %d��\n", today.year, today.month, today.day);

	return 0;
}

struct point {
	int x;
	int y;
};

struct point p1, p2;

struct {
	int x;
	int y;
}; p1

struct date {
	int year;
	int month;
	int day;
};

int main(void) {

	struct date today = { 2020, 2, 9 };
	struct date tomorrow = { .month = 2, .day = 9 };

	printf("%d - %d - %d\n", today.year, today.month, today.day);
	printf("%d - %d - %d\n", tomorrow.year, tomorrow.month, tomorrow.day);

	return 0;
}

struct date {
	int year;
	int month;
	int day;
}p1, p2;

int main(void) {

	//struct date p1;
	p1 = (struct date){ 2020, 2, 9 };
	p2 = (struct date){ 1010, 1, 5 };

	p2 = p1;

	printf("%d - %d - %d\n", p2.year, p2.month, p2.day);

	return 0;
}
int main(void) {

	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(long));
	return 0;
}

#include<stdbool.h>

struct date {
	int month;
	int day;
	int year;
	//�� - �� - �� �۵ù��ʻ���
};

bool isleap(struct date d);//�ж��Ƿ�Ϊ����
int NumberOfDays(struct date d);//�ж�����
bool ErrorInputCheck(struct date d);//����Ƿ��ǺϷ�����

int main(void) {

	struct date today, tomorrow;
	int flag = 0;

	printf("Input today's date:(format: month day year)\n");
	scanf("%d %d %d", &today.month, &today.day, &today.year);

	if (ErrorInputCheck(today))
		return 0;

	if (today.day != NumberOfDays(today)) {

		tomorrow = today;
		tomorrow.day++;

	}
	else if (today.month != 12) {

		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;

	}
	else {

		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;

	}

	printf("%d - %d - %d\n", tomorrow.month, tomorrow.day, tomorrow.year);

	return 0;
}

bool ErrorInputCheck(struct date d) {

	bool flag = false;

	if (d.day <= 0 || d.day > 31) {

		printf("illegal input of day!\n");
		flag = true;

	}
	if (d.month <= 0 || d.month > 12) {

		printf("illegal input of month!\n");
		flag = true;

	}
	if (d.year < 0) {

		printf("illegal year!\n");
		flag = true;

	}

	return flag;
}

int NumberOfDays(struct date d) {

	int day = 0;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (d.month == 2 && isleap)
		day = 29;
	else
		day = days[d.month - 1];

	return day;
}

bool isleap(struct date d) {

	bool leap = false;
	int year = d.year;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		leap = true;

	return leap;
}

struct date {
	int month;
	int day;
	int year;
}myday;

int main(void) {

	struct date* p = &myday;

	//���ַ���ָ��ṹ�������Ա��ʽ
	(*p).month = 12;

	p->month = 12;

	return 0;
}

struct point {
	int month;
	int day;
	int year;
};

struct point* getStruct(struct point* p);//����ṹ�庯��

void outputStruct(struct point p);//����ṹ�庯��

void printStruct(const struct point* p);//����ṹ�庯��

int main(void) {

	struct point y = { 0, 0, 0 };

	*getStruct(&y);
	//	*getStruct(&y) = (struct point){ 0, 0, 0 };

	outputStruct(y);
	outputStruct(*getStruct(&y));

	printStruct(&y);

	return 0;
}

struct point* getStruct(struct point* p) {

	printf("Input a date\n");
	scanf("%d", &p->month);
	scanf("%d", &p->day);
	scanf("%d", &p->year);

	return p;
}

void outputStruct(struct point p) {

	printf("outputStruct��\n");
	printf("%d - %d - %d\n", p.month, p.day, p.year);
}

void printStruct(const struct point* p) {

	printf("printStruct:\n");
	printf("%d - %d - %d\n", p->month, p->day, p->year);
}

struct date {
	int month;
	int day;
	int year;
};

struct date dates[100];
struct date datess[2] = { {2, 9, 2020}, {2, 10, 2020} };

struct time {
	int hour;
	int minute;
	int second;
};

struct time* timeUpdate(struct time* p) {

	if (p->second != 59) {
		p->second++;
	}
	else if (p->minute != 59) {
		p->second = 0;
		p->minute++;
	}
	else if (p->hour != 23) {
		p->second = 0;
		p->minute = 0;
		p->hour++;
	}
	else {
		p->second = 0;
		p->minute = 0;
		p->hour = 0;
	}
	return p;
}

int main(void) {

	struct time testTimes[5] = {
		{11, 59, 59}, {12, 0, 0}, {1, 29, 59}, {23, 59, 59}, {19, 12, 27}
	};
	int i = 0;

	for (i = 0; i < 5; i++) {

		printf("Now the time is:%d - %d - %d\n",
			testTimes[i].hour, testTimes[i].minute, testTimes[i].second);

		testTimes[i] = *timeUpdate(&testTimes[i]);

		printf("one second letter:%d - %d - %d\n",
			testTimes[i].hour, testTimes[i].minute, testTimes[i].second);
	}

	return 0;
}

//����ṹ���ʾ ��ά����ϵ�е������
struct point {
	int x;
	int y;
};

//����ṹ���ʾһ������ (����ȷ��һ������)
struct rectangle {
	struct point p1;
	struct point p2;
};

int main(void) {

	struct rectangle r;
	r.p1.x;
	r.p2.y;

	return 0;
}

struct point {
	int x;
	int y;
};

struct rectangle {
	struct point p1;
	struct point p2;
	struct point* p3;
};

int main(void) {

	struct rectangle r, * pr;

	r.p1.x;
	(r.p1).x;

	pr->p1.x;
	(pr->p1).x;
	//Ϊʲô���� point ����Ҫ�� -> �أ�
	//��Ϊ�� rectangle �� point ������ָ��ṹ��

	pr->p3->x;

	return 0;
}

struct point {
	int x;
	int y;
};

struct rectangle {
	struct point p1;
	struct point p2;

};

void printStruct(struct rectangle* p, int len) {

	int i = 0;

	for (i = 0; i < len; i++) {

		printf("(%d, %d) (%d, %d)\n", p[i].p1.x, p[i].p1.y, p[i].p2.x, p[i].p2.y);
	}
}

int main(void) {

	struct rectangle rects[] = {
		{{2, 2}, {4, 4} },
		{{5, 6}, {7, 8} }
	};
	int len = sizeof(rects) / sizeof(rects[0]);

	printStruct(rects, len);

	return 0;
}

struct {
	int x, y;
} s[2] = {
	{1, 3},
	{2, 7}
};

printf("%d\n", s[0].y / s[1].x);

struct sk {
	int a;
	float b;
}data, * p = &data;

A:	(*p).data.a;
B:	(*p).a;
C:	p->data.a;
D:	p.data.a;

struct { int x; int y; }x;
struct { int x; int y; }y;

A: ��
B : ��

typedef long int64_t;

typedef struct Adate {
	int month;
	int day;
	int year;
}date;

int main(void) {

	int64_t i = (int64_t)1e+10;
	date d = { 2, 10, 2020 };

	return 0;
}

typedef struct {
	int month;
	int day;
	int year;
}Date;

union AnEit {
	int i;
	char c;
}elt1, elt2;

int main(void) {

	elt1.i = 4;
	elt2.c = 'a';
	elt2.i = 0xDEADBEEF;

	return 0;
}

typedef union {
	int i;
	char ch[sizeof(int)];
}CHI;

int main(void) {

	CHI chi;
	int i;
	chi.i = 1234;
	for (i = 0; i < sizeof(int); i++) {
		printf("%02hhx", chi.ch[i]);
	}
	printf("\n");

	return 0;
}


