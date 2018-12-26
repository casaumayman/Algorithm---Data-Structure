#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,bit[65];
int T;
void Input()
{
	cin>>A>>B;
}
int sl(ll x)
{
	int temp=0;
	for (int i=63;i>=1;i--)
		if (x>=bit[i])
		{
			//cout<<i<<"\n";
			temp++;
			x-=bit[i];
			if (x==0) return temp;
		}
	return temp;
}
int Solve(ll x,ll y)
{
	if ((!y && x) || y==1) return -1;
	if (x==y) return 0;
	if (sl(y-1)>sl(x))
	{
		return (sl(y-1)-sl(x))+1;
	}
	else if (sl(y-1)<sl(x))
	{
		return 2;
	}
	else return 1;
}
void Process()
{
	Input();
	cout<<Solve(A,B)<<"\n";
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	bit[1]=1;
	for (int i=2;i<=64;i++) bit[i]=bit[i-1]<<1;
	cin>>T;
	while (T--) Process();
	return 0;
}

