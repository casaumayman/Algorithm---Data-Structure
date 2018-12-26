#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair <int,int> ii;
ii a,b;
map <ii,bool> m;
int res;
struct ele{
    ii v;
    int coun;
    ele(){}
    ele(int a,int b,int c){
        v.f=a;
        v.s=b;
        coun=c;
    }
    ele(ii k,int c){
        v=k;
        coun=c;
    }
};
void BFS(){
    queue <ele> q;
    q.push(ele(a,0));
    ele t;
    while (!q.empty()){
        t=q.front();
        q.pop();
        if (m[t.v]==true || t.v.f>1000 || t.v.s>1000) continue;
        if (t.v==b){
            res=t.coun;
            return;
        }
        m[t.v]=false;
        q.push(ele(t.v.f+t.v.s,t.v.s,t.coun+1));
        q.push(ele(t.v.s,t.v.f,t.coun+1));
        if (t.v.f-t.v.s>0) q.push(ele(t.v.f-t.v.s,t.v.s,t.coun+1));
    }
    res=-1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>a.f>>a.s>>b.f>>b.s;
	BFS();
	cout<<res<<"\n";
	return 0;
}
