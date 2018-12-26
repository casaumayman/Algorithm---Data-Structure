#include<bits/stdc++.h>
using namespace std;
int T,n,a[10001];
int cal(int x,int k)
{
	int t=0;
	x-=k;
	if (x>=5)
	{
		t+=x/5;
		x%=5;
	}
	if (x>=2)
	{
		t+=x/2;
		x%=2;
	}
	t+=x;
	return t;
}
void Process()
{
	cin>>n;
	int sum=0,mins=INT_MAX,minn=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]<mins) mins=a[i];
	}
	for (int j=0;j<=mins;j++)
	{
		sum=0;
		for (int i=1;i<=n;i++)
			sum+=cal(a[i],j);
		if (sum<minn) minn=sum;
	}
	cout<<minn<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) Process();
	return 0;
}
