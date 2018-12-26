#include <bits/stdc++.h>
using namespace std;
long long t[400001];
long long a[100001];
int n,q;
void Input(){
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void build(int k,int l,int r)
{
    if (l>r) return;
    if (l==r){
        t[k]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    t[k]=t[k*2]+t[k*2+1];
}
long long getsum(int k,int l,int r,int u,int v){
    if (u>r || v<l) return 0;
    if (l>=u && r<=v) return t[k];
    int m=(l+r)/2;
    return getsum(k*2,l,m,u,v)+getsum(k*2+1,m+1,r,u,v);
}
int main() {
    Input();
    build(1,1,n);
    int l,r;
    while (q--){
        cin>>l>>r;
        cout<<getsum(1,1,n,l,r)<<"\n";
    }
    return 0;
}
