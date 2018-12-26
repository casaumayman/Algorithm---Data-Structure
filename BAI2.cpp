#include <stdio.h>
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void Quick_Sort(int a[],int l,int r){
    int m = a[(l + r) / 2], i = l, j = r;
    while (i <= j){
        while (a[i] > m) i++;
        while (a[j] < m) j--;
        if (i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l < j) Quick_Sort(a,l,j);
    if (r > i) Quick_Sort(a,i,r);
}
int main(){
    int n, a[101];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	Quick_Sort(a,1,n);
	for (int i = 2; i <= n; i++){
        for (int j = i - 1; j >= 1; j--){
            if (a[j] == 0) {
                printf("%d", i - 1);
                return 0;
            }
            a[j]--;
        }
	}
	printf("%d",n);
	return 0;
}
