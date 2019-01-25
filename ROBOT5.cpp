#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll x,y,c;
void Process(){
    cin>>x>>y>>c;
    ll _x,_y;
    _x = (x+y)/2;
    _y = (2*x*y)/(x+y);
    ll r = _x*_x + _y*_y;
    if (r>c*c) cout<<"SAFE\n";
    else cout<<"DANGER\n";
    //cout<<r<<" "<<c*c;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>t;
	while (t--) Process();
	return 0;
}
