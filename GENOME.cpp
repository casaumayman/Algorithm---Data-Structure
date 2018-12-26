#include<bits/stdc++.h>
using namespace std;
const long long BASE=1000000009;
long long power[31],a[30001][31],b[900001],c[31];
int n,k;
long long hash(int i, int l, int r)
{
	return (a[i][r] - a[i][l-1] * power[r-l+1] + BASE * BASE) % BASE;
}
bool check(int mid)
{
	int m = 0; c[0] = -1;
	for (int i=1; i<=n; i++)
    {
        int p = 0;
		for (int j=1; j<=30-mid+1; j++)
			{
				p++;
				c[p] = hash(i,j,j+mid-1);
			}
        sort(c+1,c+1+p);
        for (int j=1; j<=p; j++)
            if (c[j] != c[j-1]) {m++; b[m] = c[j];}
    }
	sort(b+1,b+1+m);
	int ans = 0,res=-1; b[0] = -1;
	for (int i=1; i<=m; i++)
		if (b[i] == b[i-1]) ans++;
		else
		{
			res = max(res, ans);
			ans = 1;
		}
	if (res >= k) return true;
	return false;
}
void Input()
{
	power[0] = 1;
	for (int i=1; i<=30; i++) power[i] = (power[i-1] * 26) % BASE;
	cin>>n>>k;
	for (int i=1; i<=n; i++)
	{
		char c;
		for (int j=1; j<=30; j++)
		{
			cin>>c;
			a[i][j] = (a[i][j-1] * 26 + c - 65) % BASE;
		}
	}
}
void Process()
{
	Input();
	int l = 1, r = 30;
	while (l<=r)
	{
		int mid = (l+r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	if (r==0) cout<<-1;
	else cout<<r;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	Process();
	return 0;
}
