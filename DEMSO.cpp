#include<bits/stdc++.h>
using namespace std;
int dem[100005],n;
long long x;
bool check[100001];
int main()
{
	for (int i=2;i<=sqrt(100000);i++)
		for (int j=i*i;j<=100000;j+=i)
			if (!check[j])
			{
				dem[i]++;
				check[j]=true;
			}
	cin>>n;
	while (n--)
	{
		cin>>x;
		if (x>100000) cout<<"0\n";
		else cout<<dem[x]+1<<"\n";
	}
	return 0;
}
