#include<bits/stdc++.h>
using namespace std;
int a,b,c;
void Process(){
    cin>>a>>b>>c;
    if (c>b) swap(b,c);
    b -= c;
    a += c*2;
    if (!(b%3) && a) cout<<"YES";
    else cout<<"NO";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
