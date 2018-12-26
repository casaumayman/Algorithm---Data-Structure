#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100001],t;
void Input()
{
	cin>>n>>t;
	long long x;
	int maxs=0,j;
	for (int i=1;i<=n;i++) cin>>x,a[i]=a[i-1]+x;
	a[n+1]=1e15;
	for (int i=1;i<=n;i++)
	{
		if (a[i]-a[i-1]>t) continue;
		j=upper_bound(a+i,a+n+1,t+a[i-1])-a;
		if (a[j]-a[i-1]>t) j--;
		if (a[j]-a[i-1]<=t) maxs=max(maxs,j-i+1);
	}
	cout<<maxs;
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Input();
	return 0;
}

