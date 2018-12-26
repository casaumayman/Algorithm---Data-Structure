#include<bits/stdc++.h>
using namespace std;
int a[50001],b[50001],n,m,k;
struct so
{
	int vta,vtb,val;
};
struct cmp
{
	bool operator()(so a,so b)
	{
		return (a.val>b.val);
	}
};
so make_so(int a,int b,int c)
{
	so t;
	t.val=a;
	t.vta=b;
	t.vtb=c;
	return t;
}
priority_queue<so,vector<so>,cmp > heap;
void Process()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for (int i=1;i<=m;i++) heap.push(make_so(a[1]+b[i],1,i));
	int x=1;
	so t;
	for (int i=1;i<=k;i++)
	{
		t=heap.top();
		heap.pop();
		if (x<n) heap.push(make_so(a[t.vta+1]+b[t.vtb],t.vta+1,t.vtb));
		cout<<t.val<<" ";
	}
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

