#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
struct node{
    int val,pos;
    node(){}
    node(int a,int b){
        val = a;
        pos = b;
    }
} it[400000];
void build(int k,int l,int r){
    if (l==r){
        it[k].val=a[l];
        it[k].pos=l;
        return;
    }
    int m = (l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    if (it[k*2].val<it[k*2+1].val){
        it[k].val = it[k*2].val;
        it[k].pos = it[k*2].pos;
    }
    else{
        it[k].val = it[k*2+1].val;
        it[k].pos = it[k*2+1].pos;
    }
}
void input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
//    for (int i=1;i<=16;i++) cout<<it[i].val<<" ";
//    cout<<"\n";
//    for (int i=1;i<=16;i++) cout<<it[i].pos<<" ";
}
void update(int k,int l,int r,int i,int v){
        if (i<l || i>r) return;
        if (it[k].val > v){
            it[k].val = v;
            it[k].pos = i;
        }
        if (l == r) return;
        int m = (l+r)/2;
        update(k*2,l,m,i,v);
        update(k*2+1,m+1,r,i,v);
}
node getMin(int k,int l,int r,int u,int v){
    if (l>v || r<u) return node(INT_MAX,-1);
    cout<<l<<" "<<r<<" "<<it[k].val<< "\n";
    if (u<=l && v>=r) return it[k];
    int m = (l+r)/2;
    node temp1 = getMin(k*2,l,m,u,v);
    node temp2 = getMin(k*2,m+1,r,u,v);
    if (temp1.val < temp2.val) return temp1;
    return temp2;
}
void process(){
    input();
    vector <pair <int,int> > kq;
    node mins;
    mins = getMin(1,1,n,2,3);
    cout<<mins.val<<" "<<mins.pos;
//    for (int i=1;i<n;i++){
//        mins = getMin(1,1,n,i+1,n);
//        if (mins.val < a[i]) {
//            kq.push_back(make_pair(i,mins.pos));
//            update(1,1,n,mins.pos,a[i]);
//        }
//    }
//    for (int i=0; i<kq.size(); i++) cout<<kq[i].first<<" "<<kq[i].second<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	process();
	return 0;
}
