#include<bits/stdc++.h>
using namespace std;
int n,mins=1000000001,a[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++)
		if (a[i+1]-a[i]<mins) mins=a[i+1]-a[i];
	cout<<mins;
	return 0;
}
