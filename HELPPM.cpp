#include<bits/stdc++.h>
using namespace std;
int m,n,key,a[501][501];
struct kq
{
	int u,v,area;
};
void Input()
{
	cin>>m>>n>>key;
	int x;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>x;
			a[i][j]=a[i][j-1]+x;
			//cout<<a[i][j]<<" ";
		}
		//cout<<"\n";
	}
}
int getsum(int row,int i,int j)
{
	return a[row][j]-a[row][i-1];
}
kq calc(int ci,int cj)
{
	kq k;
	int i=1,j=1,sum=getsum(1,ci,cj),minn=INT_MAX;
	while (i<=j && j<=m)
	{
		if (sum<key)
		{
			j++;
			sum+=getsum(j,ci,cj);
		}
		else
		{
			if (j-i+1<minn)
			{
				minn=j-i+1;
				k.u=i;
				k.v=j;
			}
			sum-=getsum(i,ci,cj);
			i++;
		}
	}
	if (minn==INT_MAX) k.area=INT_MAX;
	else
	{
		k.area=(cj-ci+1)*(k.v-k.u+1);
		//cout<<k.area<<"\n";
	}
	return k;
}
void Process()
{
	Input();
	kq res;
	int x,y,u,v,dt=INT_MAX;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			res=calc(i,j);
			if (res.area<dt)
			{
				dt=res.area;
				x=res.u;
				y=i;
				u=res.v;
				v=j;
			}
		}
	if (dt==INT_MAX) cout<<-1;
	else
	{
		cout<<dt<<"\n";
		cout<<x<<" "<<y<<" "<<u<<" "<<v;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
