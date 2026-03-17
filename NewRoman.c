#include <stdio.h>
int a[5] = {1, 2, 3, 4, 5};

int main(void) {
	int *ptr = (int *)(&a + 1);
	printf("%d, %d\n", *(a + 1), *(ptr - 1));
	printf("%p, %d\n", (a+1),*(a+1));
	return 0;
}