#include<bits/stdc++.h>
using namespace std;
int a[5001],b[5001];
int n,k,T,x,y;
long long sumarray(int a[],int n)
{
	long long t=0;
	for (int i=1;i<=n;i++) t+=(long long)a[i];
	return t;
}
bool cmp(int a,int b)
{
	return (a>b);
}
void Input()
{
	cin>>n>>k;
	int p;
	x=0; y=0;
	for (int i=1;i<=n;i++)
	{
		cin>>p;
		if (i%2==1)
		{
			x++;
			a[x]=p;
		}
		else
		{
			y++;
			b[y]=p;
		}
	}
	sort(a+1,a+x+1,cmp);
	sort(b+1,b+y+1);
}
void Process()
{
	Input();
	int i=1,j=min(n/2,k);
	while (i<=j && a[i]>b[i])
	{
		swap(a[i],b[i]);
		i++;
	}
	if (sumarray(b,y)>sumarray(a,x)) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) Process();
	return 0;
}

