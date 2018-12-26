#include<bits/stdc++.h>
using namespace std;
string s;
char ss[100001];
int n,q;
long long a,b;
int chia(long long k)
{
	if (k%n!=0) return k%n;
	return n;
}
int main()
{
	cin>>s>>q;
	n=s.size();
	for (int i=0;i<s.size();i++) ss[i+1]=s[i];
	for (int i=1;i<=q;i++)
	{
		cin>>a>>b;
		if (ss[chia(a)]==ss[chia(b)]) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
