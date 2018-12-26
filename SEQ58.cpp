#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100001],b[100001];
void Process()
{
	cin>>n;
	ll maxs=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (min(a[i]*a[j],b[i]*b[j])>maxs) maxs=min(a[i]*a[j],b[i]*b[j]);
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
	Process();
	return 0;
}

