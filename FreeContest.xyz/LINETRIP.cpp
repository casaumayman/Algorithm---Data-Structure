#include<bits/stdc++.h>
using namespace std;
int n,a[101];
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Process(){
    Input();
    bool x = (a[1] < 0);
    bool y = (a[n] > 0);
    if (x && y){
        cout<<abs(a[1])*2 + a[n]*2;
    } else if (!x && y){
        cout<<a[n]*2;
    } else if (x && !y){
        cout<<abs(a[1])*2;
    } else cout<<0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
