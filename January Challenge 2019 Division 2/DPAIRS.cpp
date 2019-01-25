#include<bits/stdc++.h>
using namespace std;
struct ele{
    int pos,val;
};
int n,m;
ele a[200000],b[200000];
bool cmp(ele a,ele b){
    return (a.val<b.val);
}
void Input(){
    cin>>n>>m;
    int x;
    for (int i=0;i<n;i++){
        cin>>x;
        a[i].val = x;
        a[i].pos = i;
    }
    for (int i=0;i<m;i++){
        cin>>x;
        b[i].val = x;
        b[i].pos = i;
    }
    sort(a,a+n,cmp);
    sort(b,b+m,cmp);
}
void Process(){
    Input();
    int mins = min(m,n);
    for (int i=0;i<mins;i++)
        cout<<a[i].pos<<" "<<b[i].pos<<"\n";
    if (n==m)
        for (int i=1;i<n;i++) cout<<a[i].pos<<" "<<b[i-1].pos<<"\n";
    else if (n>m){
        for (int i=m;i<n;i++) cout<<a[i].pos<<" "<<b[m].pos<<"\n";
        for (int i=0;i<m-1;i++) cout<<a[i+1].pos<<" "<<b[i].pos<<"\n";
    }
    else{
        for (int i=n;i<m;i++) cout<<a[n].pos<<" "<<b[i].pos<<"\n";
        for (int i=0;i<n-1;i++) cout<<a[i].pos<<" "<<b[i+1].pos<<"\n";
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
