#include<bits/stdc++.h>
using namespace std;
int t,n,q,a[100001];
void Process()
{
	map <int,int> kq;
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int k,c,d,res;
	while (q--)
	{
		cin>>k;
		if (a[n]+(n-1)<k)
		{
			cout<<0<<"\n";
			continue;
		}
		if (kq[k])
		{
			cout<<kq[k]<<"\n";
			continue;
		}
		if (a[1]>=k)
		{
			cout<<n<<"\n";
			continue;
		}
		d=1;
		if (a[n]<k) c=n;
		else c=lower_bound(a+1,a+n+1,k)-1-a;
		res=n-c;
		d+=(k-a[c]);
		while (d<=c)
		{
			res++;
			c--;
			d+=(k-a[c]);
		}
		cout<<res<<"\n";
		kq[k]=res;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	while (t--) Process();
	return 0;
}
