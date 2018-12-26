#include<bits/stdc++.h>
using namespace std;
const int MAXN=1048577;
typedef long long int64;
int64 n,L,R,a[MAXN];
void Input()
{
	FILE *f=fopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","w");
	srand(time(NULL));
	n=10;
	L=2;
	R=7;
	fprintf(f,"%lld %lld %lld\n",n,L,R);
	for (int i=1;i<=10;i++) 
	{
		a[i]=rand()%10+1;
		fprintf(f,"%lld\n",a[i]);
	}
	fclose(f);
}
int64 Process1()
{
	map <int64,int64> ml,mr;
	int64 res=0;
	int64 il=0,ir=0;
	ml[0]=1;
	mr[0]=1;
	for (int64 i=1;i<=n;i++)
	{
		if ((--ml[a[i-1]])==0) ml.erase(a[i-1]);
		if ((--mr[a[i-1]])==0) mr.erase(a[i-1]);
		while (ml.size()<L && il<n) ml[a[++il]]++;
		while (mr.size()<R && ir<n) mr[a[++ir]]++;
		while (ir<n && mr.find(a[ir+1])!=mr.end()) mr[a[++ir]]++;
		if (ml.size()==L) res+=(ir-il+1);
	}
	return res;
}
int64 Process2()
{
	map <int64,int64> m;
	int64 res=0;
	for (int64 i=1;i<=n;i++)
	{
		for (int64 j=i;j<=n;j++)
		{
			m.clear();
			for (int64 k=i;k<=j;k++)
				m[a[k]]++;
			if (m.size()>=L && m.size()<=R) res++;
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
//	freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
//	freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	int64 kq1,kq2,sl=0;
	FILE *f=fopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w");
	do
	{
		sl++;
		Input();
		kq1=Process1();
		kq2=Process2();
		cout<<sl<<"\n";
	} while (kq1==kq2);
	fprintf(f,"%lld %lld",kq1,kq2);
	fclose(f);
	return 0;
}

