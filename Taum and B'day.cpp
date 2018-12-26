#include<bits/stdc++.h>
using namespace std;
long long T,b,bc,wc,z,w;
void Process(){
    cin>>b>>w>>bc>>wc>>z;
    if (wc - z > bc) wc = bc+z;
    else if (bc - z > wc) bc = wc+z;
    long long res = (w*wc)+(b*bc);
    cout<<res<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) Process();
	return 0;
}
