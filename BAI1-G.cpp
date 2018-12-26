#include<bits/stdc++.h>
using namespace std;
int n,k;
void Input(){
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\Tasks\\BAI1\\TEST10\\BAI1.INP","w");
    srand(time(NULL));
    n = rand() % 10 + 1;
    k = rand() % 9 + 1;
    fprintf(f,"%d %d",n,k);
    fclose(f);
}
void Process() {
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\Tasks\\BAI1\\TEST10\\BAI1.OUT","w");
    int x=1;
    for (int i=1;i<=n;i++) {
        fprintf(f,"%d ",x);
        cout<<x<<" ";
        x *= k;
    }
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
