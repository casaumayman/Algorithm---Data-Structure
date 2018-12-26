#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void Input(){
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI3\\TEST10\\BAI3.INP","w");
    srand(time(NULL));
    n = 100000;
    fprintf(f,"%d\n",n);
    for (int i = 1; i <= n; i++){
        a[i] = 999999999;
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
}
void Process() {
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI3\\TEST10\\BAI3.OUT","w");
    sort(a+1,a+n+1);
    int result = INT_MAX, min_i;
	for (int i = 1; i < n; i++)
        if (a[i + 1] - a[i] < result){
            result = a[i + 1] - a[i];
            min_i = i;
        }
    printf("%d %d",a[min_i], a[min_i + 1]);
    fprintf(f,"%d %d", a[min_i], a[min_i + 1]);
    fclose(f);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Input();
	Process();
	return 0;
}
