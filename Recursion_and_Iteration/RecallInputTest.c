#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
    int num,sum=0;
    char ch;
	while (scanf("%d", &num) == 1  && num != -1) {
        sum+=num;
        ch = getchar();
    if (ch == '\n' || ch == EOF) break;
    }
    printf("%d",sum);
	  
	  /*********End**********/ 
       return 0;
	}
