#include <stdio.h>
const int oo = 999999999;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void Quick_Sort(int a[], int l, int r){
    int m = a[(l + r) / 2], i = l, j = r;
    while (i <= j){
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) Quick_Sort(a, l, j);
    if (r > i) Quick_Sort(a, i, r);
}
int main(){
    int n, a[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	Quick_Sort(a, 0, n - 1);
	int result = oo, min_i;
	for (int i = 0; i < n - 1; i++)
        if (a[i + 1] - a[i] < result){
            result = a[i + 1] - a[i];
            min_i = i;
        }
    printf("%d %d",a[min_i], a[min_i + 1]);
	return 0;
}
