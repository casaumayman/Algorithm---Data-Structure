#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll a[100001];
void Input(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Process(){
    Input();
    ll mins = INT_MAX,d,c,step;
    for (int i=1;i<=n-k+1;i++){
        d = a[i];
        c = a[i+k-1];
        if (d<0 && c<=0) step = d;
        if (d>=0 && c>0) step = c;
        if (d==0 && c==0) {
            cout<<0;
            return;
        }
        if (d<0 && c>0) {
            if (abs(d) < abs(c)){
                step = abs(d)*2 + abs(c);
            }
            else {
                step = abs(c)*2 + abs(d);
            }
        }
        //cout<<d<<" "<<c<<" "<<step<<"\n";
        if (step < mins) mins = step;
    }
    cout<<mins;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
