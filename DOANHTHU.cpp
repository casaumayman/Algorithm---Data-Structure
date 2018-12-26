#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[100001];
void Process()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (k>n) k=n;
	int x=k;
	for (int i=1;i<=k;i++)
	{
		if (a[i]>=0) break;
		else a[i]=-a[i];
		x--;
	}
	sort(a+1,a+n+1);
	if (x%2==1) a[1]=-a[1];
	long long sum=0;
	for (int i=1;i<=n;i++) sum+=a[i];
	cout<<sum;
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

