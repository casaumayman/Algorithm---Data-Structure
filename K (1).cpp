#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int giai(char n[200])
	{
		char h;
		for (int i=0;i<strlen(n);i++)
			{
				h=n[i];
				if ((n[i]!='6')&&(n[i]!='8'))
					{
						return 1;
					}
			}
		return 0;
	}
int main()
{
	char buffer[200];
	char n[200];
	scanf("%s",&n);
	//fgets(buffer,256,stdin);
	int a;
  	a=atoi(n);
  	//printf("%d\n",a);
//-----------------------------
	for (int i=a;i>5;i--)
		{
		itoa(i,buffer,10);
		if (giai(buffer)==0) 
			{
			printf("%d ",i);
			return 0;
			}
		}
	}
