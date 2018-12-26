#include<bits/stdc++.h>
using namespace std;
int T,n,a[100001],K;
bool cmp(int a,int b){
    return (a>b);
}
int find(int l,int r,int value){
    int ll = l, rr = r, m = (ll + rr) / 2,temp = -1;
    while (ll <= rr){
        if (a[m] >= value) {
            ll = m + 1;
            if (a[m] == value) temp = m;
        }
        else rr = m - 1;
        m = (ll + rr) / 2;
    }
    return temp;
}
void Input(){
    cin>>n>>K;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int f = find(K+1,n,a[K]);
    if (f == -1) cout<<K<<"\n";
    else cout<<f<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    while (T--) Input();
    return 0;
}
