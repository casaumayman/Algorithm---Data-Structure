#include<bits/stdc++.h>
using namespace std;
int n,a[101];
void Input(){
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI2\\TEST10\\BAI2.INP","w");
    srand(time(NULL));
    n = rand() % 100 + 1;
    fprintf(f,"%d\n",n);
    for (int i = 1; i <= n; i++){
        a[i] = rand() % 101;
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
}
bool cmp(int a, int b){
    return (a > b);
}
void Process() {
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI2\\TEST10\\BAI2.OUT","w");
    sort(a+1,a+n+1,cmp);
    for (int i = 2; i <= n; i++){
        for (int j = i - 1; j >= 1; j--){
            if (a[j] == 0) {
                printf("%d", i - 1);
                fprintf(f, "%d", i - 1);
                return;
            }
            a[j]--;
        }
	}
	cout<<n;
	fprintf(f,"%d",n);
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
