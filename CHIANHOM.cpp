#include<bits/stdc++.h>
using namespace std;
int n;
bool xuathien[1000001];
int cha[1000001],a[1000001];
int not_nt[1000001];
bool check[1000001];
int root(int i)
{
	if (cha[i]==-1) return i;
	cha[i]=root(cha[i]);
	return cha[i];
}
void merge(int x,int y)
{
	if ((x=root(x))==(y=root(y))) return;
	cha[x]=y;
}
void Input()
{
	cin>>n;
	int x;
	for (int i=1;i<=1000000;i++) cha[i]=-1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		xuathien[a[i]]=true;
	}
	for (int i=2;i<=1000;i++)
		if (!not_nt[i])
			for (int j=i;j<=1000001;j+=i)
			{
				not_nt[j]=true;
				if (xuathien[j]) {
							merge(i,j);// cout<<i<<" "<<j<<"\n";
						}
			}
	int res=0;
	for (int i=1;i<=n;i++) 
		if (!check[root(a[i])])
		{
			res++;
			check[root(a[i])]=true;
		}
	cout<<res;
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Input();
	return 0;
}

