#include<bits/stdc++.h>
using namespace std;
int n,m,P;
long long B,T;
struct opj
{
	int stt;
	long long cost;
} nha[21];
bool cmp(opj a,opj b)
{
	return (a.cost<b.cost);
}
int bus[1001];
void Input()
{
	cin>>n>>m>>P>>T>>B;
	for (int i=1;i<=m;i++)
	{
		cin>>nha[i].cost;
		nha[i].stt=i;
	}
	sort(nha+1,nha+m+1,cmp);
	bus[1]=1;
	for (int i=2;i<=P+1;i++) cin>>bus[i];
	bus[P+2]=n;
	P+=2;
}
long long bsearch(long long x)
{
	long long left=1,right=P,mid;
	while (left!=mid && right!=mid)
	{
		mid=(left+right)/2;
		if (bus[mid]<=x) left=mid;
		else right=mid;
	}
	long long kq=999999999999;
	for (int i=left;i<=right;i++) kq=min(kq,abs(bus[i]-x));
	return kq;
}
long long gia(int x,int y)
{
	int nearx=bsearch(x);
	int neary=bsearch(y);
	long long temp;
	temp=(nearx*T+neary*T+B);
	return min(abs(x-y)*T,temp);
}
void Process()
{
	Input();
	long long res=gia(1,nha[1].cost);
	for (int i=2;i<=m;i++) res+=gia(nha[i-1].cost,nha[i].cost);
	res+=gia(nha[m].cost,n);
	cout<<res<<"\n";
	for (int i=1;i<=m;i++) cout<<nha[i].stt<<" ";
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
