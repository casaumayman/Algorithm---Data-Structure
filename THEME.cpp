#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void Process()
{
	int maxs=1,j,k,l,m;
	for (int i=1;i<n-5;i++)
	{
		for (k=i+5;k<n-5;k++)
		{
			l=1;
			j=i;
			m=k;
			while (a[j+1]-a[j]==a[k+1]-a[k])
			{
				k++;
				j++;
				l++;
				if (l>maxs) maxs=l;
				if (j+1==m) break;
				if (k==n) break;
			}
		}
	}
	if (maxs<5) cout<<0;
	else cout<<maxs;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Input();
	Process();
	return 0;
}
