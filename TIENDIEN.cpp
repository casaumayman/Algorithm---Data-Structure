#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if (n<=0) n=0;
	else if (n<=50) n*=1484;
	else if (n<101) n*=1533;
	else if (n<201) n*=1768;
	else if (n<301) n*=2242;
	else if (n<401) n*=2503;
	else n*=2587;
	printf("%d",n);
	return 0;
}
