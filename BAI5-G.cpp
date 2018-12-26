#include<bits/stdc++.h>
using namespace std;
int n, a[10001];
void Input(){
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI5\\TEST10\\BAI5.INP","w");
    srand(time(NULL));
    n = 10000;
    int pos = (rand() % n) + 1;
    fprintf(f,"%d\n",n);
    for (int i = 1; i <= n; i++){
        if (i == pos) a[i] = rand() % n;
        else a[i] = i*i;
        fprintf(f,"%d ",a[i]);
    }
    fclose(f);
}
void Process() {
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI5\\TEST10\\BAI5.OUT","w");
    sort(a + 1, a + n + 1);
    int result = 1;
    for (int i = 1; i <= n; i++)
        if (sqrt(a[i]) == result) result++;
    cout<<result * result;
    fprintf(f,"%d",result * result);
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
