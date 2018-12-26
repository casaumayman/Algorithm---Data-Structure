#include<bits/stdc++.h>
using namespace std;
long long a[500001],mins=999999999;
int n,h,sl;
void Process()
{
	cin>>n>>h;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		if (i%2) a[h-x+1]++;
		else
		{
			a[1]++;
			a[x+1]--;
		}
	}
	for (int i=1;i<=h;i++)
	{
		a[i]=a[i-1]+a[i];
		if (a[i]<mins) mins=a[i];
	}
	for (int i=1;i<=h;i++)
		if (a[i]==mins) sl++;
	cout<<mins<<" "<<sl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
