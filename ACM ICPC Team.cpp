#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[501][501];
int kq[501];
void Input(){
    cin>>n>>m;
    char x;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            cin>>x;
            a[i][j] = (x == '0')?false:true;
        }
}
void Process(){
    Input();
    int t,maxs = 0;
    for (int i=1;i<n;i++)
    for (int j=i+1;j<=n;j++){
        t = 0;
        for (int k=1;k<=m;k++)
            if (a[i][k] || a[j][k]) t++;
        kq[t]++;
        if (t > maxs) maxs = t;
    }
    cout<<maxs<<"\n"<<kq[maxs];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
