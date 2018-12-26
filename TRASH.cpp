#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1000001],t;
void Input(){
    cin>>n>>t;
    int x;
    for (int i=1;i<=n;i++){
        cin>>x;
        a[i]=a[i-1]+x;
    }
}
int Find(int i){
    int l=i,r=n,m=(l+r)/2,kq;
    while (l<=r){
        if (a[m]-a[i-1]<=t){
            kq=m;
            l=m+1;
        }
        else r=m-1;
        m=(l+r)/2;
    }
    return kq;
}
void Process(){
    Input();
    ll res=0;
    int bs;
    for (int i=1;i<=n;i++){
        if (a[i]-a[i-1]>t) continue;
        bs=Find(i);
        res+=((ll)bs-(ll)i+1);
    }
    cout<<res<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
