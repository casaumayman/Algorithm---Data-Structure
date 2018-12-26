#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct opj
{
	ll w,v;
} a[33];
bool cmp(opj t,opj k)
{
	if (t.w==k.w) return (t.v<k.v);
	return (t.w<k.w);
}
vector <opj> kq;
ll U,V,tree[(1<<16)*4],x,y,res;
opj make(ll x,ll y)
{
	opj t;
	t.w=x;
	t.v=y;
	return t;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tree[k]=kq[l].v;
		return;
	}
	int mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	tree[k]=max(tree[k<<1],tree[(k<<1)+1]);
}
ll get(int k,int l,int r,int u,int v)
{
	if (r<u || l>v) return 0;
	if (u<=l && r<=v) return tree[k];
	int mid=(l+r)>>1;
	return max(get(k<<1,l,mid,u,v),get((k<<1)+1,mid+1,r,u,v));
}
void Input()
{
	cin>>n>>U>>V;
	for (int i=1;i<=n;i++)
		cin>>a[i].w>>a[i].v;
	kq.push_back(make(-1e18,0));
}
void submit1(int i)
{
	if (i>n/2)
	{
		kq.push_back(make(x,y));
		return;
	}
	for (int chon=0;chon<=1;chon++)
		if (chon)
		{
			x+=a[i].w;
			y+=a[i].v;
			submit1(i+1);
			x-=a[i].w;
			y-=a[i].v;
		}
		else submit1(i+1);
}
int find(ll x)
{
	int left=1,right=kq.size()-1,mid=(left+right)/2;
	while (left<right)
	{
		//cout<<"vi tri "<<left<<" "<<mid<<" "<<right<<"\n";
		if (kq[mid].w>=x) right=mid;
		else left=mid+1;
		mid=(left+right)/2;
	}
	return mid;
}
void submit2(int i)
{
	if (i>n)
	{
		if (x>V) return;
		int d,c;
		d=find(U-x);
		c=find(V-x);
		if (kq[c].w+x>V) c--;
		if (d<=c) res=max(res,get(1,1,kq.size()-2,d,c)+y);
		return;
	}
	for (int chon=0;chon<=1;chon++)
		if (chon)
		{
			x+=a[i].w;
			y+=a[i].v;
			submit2(i+1);
			x-=a[i].w;
			y-=a[i].v;
		}
		else submit2(i+1);
}
void Process()
{
	Input();
	submit1(1);
	kq.push_back(make(1e18,11));
	sort(kq.begin(),kq.end(),cmp);
	x=y=0;
	build(1,1,kq.size()-2);
	submit2(n/2+1);
//	for (int i=1;i<kq.size();i++)
//	{
//		cout<<kq[i].w<<" "<<kq[i].v<<"\n";
//	}
	cout<<res;
	//cout<<find(11);
}
int main()
{
 	#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Process();
	return 0;
}
