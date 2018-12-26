#include<bits/stdc++.h>
using namespace std;
long long coun,n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>n;
	long long x,kq,t;
	for (int k=1;k<=n;k++)
	{
		kq=0;
		cin>>coun;
		coun--;
		for (int i=1;i<=25;i++)
		{
			cin>>x;
			if (x<coun)
			{
				kq+=x;
				coun-=x;
			}
			else if (coun<x)
			{
				kq+=coun;
				coun=x-coun;
			}
			else
			{
				kq+=x;
				coun=0;
			}
		}
		cout<<kq<<"\n";
	} 
	return 0;
}

