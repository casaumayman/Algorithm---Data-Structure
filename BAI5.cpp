#include <stdio.h>
#include <math.h>
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
    int n, a[100001];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    Quick_Sort(a, 0, n - 1);
    int result = 1;
    for (int i = 0; i < n; i++)
        if (sqrt(a[i]) == result) result++;
    printf("%d", result * result);
    return 0;
}
