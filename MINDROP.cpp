#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void Process()
{
	cin>>n;
	a[0]=-1;
	int dem=1,maxs=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==a[i-1]) dem++;
		else dem=1;
		maxs=max(maxs,dem);
	}
	cout<<n-maxs;
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

