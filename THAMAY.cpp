#include<bits/stdc++.h>
using namespace std;
int n,k,a[2001];
void Input(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Process(){
    Input();
    int res = 0;
    for (int i=n;i>=1;i-=k) res += (a[i]-1)*2;
    cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
