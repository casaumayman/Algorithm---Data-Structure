#include<bits/stdc++.h>
using namespace std;
int n;
struct doan
{
	int d,c;
};
struct ele
{
	int val;
	doan ind;
};
ele make(int a,int b,int c)
{
	ele t;
	t.val=a;
	t.ind.d=b;
	t.ind.c=c;
	return t;
}
struct cmp
{
	bool operator() (ele a,ele b)
	{
		if (a.val==b.val)
			return (a.ind.c<b.ind.c);
		return (a.val>b.val);
	}
};
priority_queue <ele,vector<ele>,cmp> heap;
bool ke(ele a,ele b)
{
	return (a.ind.c==b.ind.d-1 || b.ind.c==a.ind.d-1);
}
void Process()
{
	cin>>n;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		heap.push(make(x,i,i));
	}
	ele u,v;
	while (heap.size()>1)
	{
		u=heap.top();
		heap.pop();
		v=heap.top();
		heap.pop();
		if (u.val==v.val && ke(u,v))
            v=make(u.val+1,min(u.ind.d,v.ind.d),max(u.ind.c,v.ind.c));
	    heap.push(v);
	}
	cout<<heap.top().val;
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

