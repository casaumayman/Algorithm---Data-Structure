#include<bits/stdc++.h>
using namespace std;
int T,n,m;
long long tong;
void Input(){
    cin>>n>>m;
    long long x;
    for (int i=1;i<=n+m;i++){
        cin>>x;
        tong += x;
    }
    if (tong % 2 == 0) cout<<"Bob";
    else cout<<"Alice";
}
void Process(){
    cin>>T;
    while (T--) Input();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
