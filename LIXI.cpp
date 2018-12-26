#include<bits/stdc++.h>
using namespace std;
struct ele
{
	int a,b;
	bool operator <(const ele &x) const
	{
		if (b==x.b) return (a>x.a);
		return (b>x.b);
	}
} tui[101];
int n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>tui[i].a>>tui[i].b;
	sort(tui+1,tui+n+1);
	int t=tui[1].a,sl=tui[1].b,i=2;
	while (sl!=0 && i<=n)
	{
		t+=tui[i].a;
		sl=sl-1+tui[i].b;
		i++;
	}
	cout<<t;
	return 0;
}
