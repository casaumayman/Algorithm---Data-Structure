#include<bits/stdc++.h>
using namespace std;
int m,n,q,T[1001][1001];
bool Not_prime[1000001];
void San()
{
	Not_prime[1]=true;
	for (int i=2;i<=1000;i++)
		if (!Not_prime[i])
			for (int j=i*i;j<=1000000;j+=i) Not_prime[j]=true;
}
void Input()
{
	cin>>m>>n>>q;
	int x;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>x;
			if (!Not_prime[x])
			{
				if (j==1) T[i][j]=T[i-1][j]+1;
				else T[i][j]=T[i-1][j]+T[i][j-1]-T[i-1][j-1]+1;
				//cout<<1<<" ";
			}
			else
			{
				if (j==1) T[i][j]=T[i-1][j];
				else T[i][j]=T[i-1][j]+T[i][j-1]-T[i-1][j-1];
				//cout<<0<<" ";
			}
			//cout<<T[i][j]<<" ";
		}
		//cout<<"\n";
	}
}
int Tong(int u,int v,int i,int j)
{
	return T[i][j]-T[u-1][j]-T[i][v-1]+T[u-1][v-1];
}
void TruyVan()
{
	int x,y,r,c;
	for (int i=1;i<=q;i++)
	{
		bool thay=false;
		cin>>x>>y>>r>>c;
		for (int r1=x;r1<=y-r+1;r1++)
		{
			for (int c1=1;c1<=n-c+1;c1++)
				if (Tong(r1,c1,r1+r-1,c1+c-1)==r*c)
				{
					thay=true;
					//cout<<r<<"\n";
					break;
				}
			if (thay) break;
		}
		if (thay) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
}
int main()
{
	San();
	Input();
	TruyVan();
	return 0;
}
