#include <stdio.h>

int main(void)
{

    printf("%d\n", 123);
    printf("%d\n", -123);
    printf("%+d\n", 123);
    printf("%+d\n", -123);
    printf("%5.2f\n", -123.234);
    printf("%10d\n", 101010);
    printf("%5d\n", 123);
    printf("%2d\n", 123);
    printf("%*d\n", 5, 123);
    printf("%*d\n", -5, 123); // -5 是一个用于指定宽度的整数值，但是负数表示要在左对齐输出，并且不会缩进
    printf("%.4d\n", 123);

    printf("%f\n", 123.0);
    printf("%.1f\n", 123.0);

    printf("%g\n", 123.0);
    printf("%.5g\n", 123.0);

    printf("%s\n", "Hello");
    printf("%.2s\n", "Hello");

    printf("%.*d\n", 4, 123);
    printf("%.*d\n", -4, 123);

    printf("%12d\n", 123123);
    printf("%-12d\n", 123123);

    // int a = 0;

	// scanf("%*d%d", &a);
	// printf("%d", a);

    // int s = 0;
	// char str[10];

	// scanf("%3d%4s", &s, str);
	// printf("%d %s", s, str);

    // 	char ch = 'a';
	// char str[10] = "hi";

	// scanf("%[123]", str);

	// printf("%c %s", ch, str);

    int i, j, k;
	
	printf("Enter a date: ");
	scanf("%d - %d - %d", &i, &j, &k);
	printf("date: %d - %d - %d", i, j, k);

    return 0;
}