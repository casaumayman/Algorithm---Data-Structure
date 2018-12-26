#include<bits/stdc++.h>
using namespace std;
string s;
int res;
int minmove(int l,int r) {
	int x, y, i, j, u, v;
	for (x = l, y = l+1; y <= r; ++ y) {
		i = u = x;
		j = v = y;
		while (s[i] == s[j]) {
			++ u; ++ v;
			if (++ i == r+1) i = l;
			if (++ j == r+1) j = l;
			if (i == x) break;
		}
		if (s[i] <= s[j]) y = v;
		else {
			x = y;
			if (u > y) y = u;
		}
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>s;
	int n=s.length();
	if (n<5)
	{
		cout<<0;
		return 0;
	}
	for (int i=0;i<=n-5;i++)
		for (int j=i+5-1;j<n;j++)
			if (minmove(i,j)==i) res++;
	cout<<res;
	return 0;
}
