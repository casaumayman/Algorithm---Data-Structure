#include<bits/stdc++.h>
using namespace std;
int n;
char a[21][21];
int dx[4]={0,1,1,1};
int dy[4]={1,1,0,-1};
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
}
bool valid(int a,int b){
    return (a>=1 && a<=n && b>=1 && b<=n);
}
bool checkk(int x,int y){
    if (a[x][y]=='.') return false;
    int coun;
    for (int k=0;k<4;k++){
        coun = 1;
        for (int h=1;h<=n;h++){
            int i = x+h*dx[k];
            int j = y+h*dy[k];
            if (valid(i,j) && a[i][j]==a[x][y]){
                coun++;
                if (coun==5) return true;
            }
            else break;
        }
    }
    return false;
}
void Process(){
    Input();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (checkk(i,j)){
                if (a[i][j]=='x') cout<<"Ti wins";
                else cout<<"Teo wins";
                return;
            }
    cout<<"Not yet";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
