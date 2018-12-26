#include<bits/stdc++.h>
using namespace std;
int n;
char a[200][200];
bool isWhite = true;
void color(int x,int y){
    for (int i=x;i<x+3;i++)
        for (int j=y;j<y+3;j++) a[i][j] = isWhite?'W':'B';
}
void Process(){
    cin>>n;
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
        if ((i+j)%2==0) isWhite = true;
        else isWhite = false;
        color(i*3,j*3);
    }
    for (int i=0;i<n*3;i++){
        for (int j=0;j<n*3;j++) cout<<a[i][j];
        cout<<"\n";
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
