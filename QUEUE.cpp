#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100001];
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void q_sort(ll l,ll r){
    ll m=(l+r)/2,i=l,j=r,t;
    while (i<=j){
        while (a[i]<a[m]) i++;
        while (a[j]>a[m]) j--;
        if (i<=j) {
            if (i != j) cout<<i<<" "<<j<<"\n";
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (i<r) q_sort(i,r);
    if (l<j) q_sort(l,j);
}
void Process(){
    Input();
    q_sort(1,n);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
