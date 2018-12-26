#include<bits/stdc++.h>
using namespace std;
int n,a[1001];
int UC(int a,int b)
{
	int r;
	while (b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int GCD(int n)
{
	int t=a[1];
	for (int i=2;i<=n;i++) t=UC(t,a[i]);
	return t;
}
void Input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}
void Process()
{
	Input();
	if (GCD(n)==1) cout<<"0\n";
	else cout<<"-1\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	int T;
	cin>>T;
	while (T--) Process();
	return 0;
}

