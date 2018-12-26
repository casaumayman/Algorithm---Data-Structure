#include<bits/stdc++.h>
using namespace std;
int q,n;
long long m;
long long max(long long a,long long b,long long c)
{
    return max(max(a,b),c);
}
set <long long> sex;
void Process()
{
	cin>>n>>m;
	sex.insert(m);
	long long sum=0,x,t,res=LONG_MIN;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		sum=(sum+x)%m;
		t=*sex.upper_bound(sum);
		res=max(sum-t+m,res);
		sex.insert(sum);
	}
	cout<<res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>q;
	while (q--)
		Process();
	return 0;
}
