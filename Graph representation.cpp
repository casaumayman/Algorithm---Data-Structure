#include<bits/stdc++.h>
using namespace std;
int n,T;
bool b[10001],c[10001];
int par[10001],vlt;
int root(int i)
{
	if (par[i]<0) return i;
	return (par[i]=root(par[i]));
}
void merge(int x,int y)
{
	int r1=root(x),r2=root(y);
	if (r1==r2) return;
	if (par[y]<par[x]) swap(x,y);
	par[x]+=par[y];
	par[y]=x;
	vlt--;
}
void Input()
{
    cin>>n;
    int x,y;
    vlt=1;
    for (int i=1;i<=n;i++)
    {
    	cin>>b[i];
    	par[i]=-1;
    }
    for (int i=1;i<=n;i++)
    {
    	cin>>c[i];
    	if (!c[i]) vlt++;
    }
}
void Process()
{
    Input();
    cout<<vlt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>T;
    while (T--) Process();
    return 0;
}
