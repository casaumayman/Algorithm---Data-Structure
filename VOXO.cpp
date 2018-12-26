	#include<bits/stdc++.h>
	using namespace std;
	int a[201][201],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	void VOXO()
	{
		a[100][100]=1;
		int so=2,huong=0,loop=1,x=50,y=50;
		while (so<=40000)
		{
			for (int k=1;k<=2;k++)
			{
				for (int i=1;i<=loop;i++)
				{
					x+=dx[huong];
					y+=dy[huong];
					a[y][x]=so++;
				}
				huong=(huong+1)%4;
			}
			loop++;
		}
	}
	int main()
	{
		VOXO();
		int x,y;
		cin>>x>>y;
		cout<<a[y+100][x+100];
		return 0;
	}
