#include <stdio.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int x = 1;
	for (int i = 1; i <= n ; i++) {
        printf("%d ",x);
        x *= k;
	}
	return 0;
}
