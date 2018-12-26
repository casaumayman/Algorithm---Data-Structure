#include<bits/stdc++.h>
#define pb insert
#define fors(a) for(it=a.begin();it!=a.end();it++)
using namespace std;
struct Company
{
	int offeredSalary,maxJobOffers,Offering;
} cty[1001];
struct ele
{
	int id,Salary;
};
ele make_ele(int id,int Salary)
{
	ele k;
	k.id=id;
	k.Salary=Salary;
	return k;
}
struct cmp
{
	bool operator()(ele a,ele b)
	{
		return (a.Salary>b.Salary);
	}
};
struct Sinhvien
{
	int minSalary;
	set <ele,cmp> Cty;
} sv[1001];
int T,m,n;
void Process()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>sv[i].minSalary;
		sv[i].Cty.clear();
	}
	for(int i=1;i<=m;i++)
	{
		cin>>cty[i].offeredSalary>>cty[i].maxJobOffers;
		cty[i].Offering=0;
	}
	char c;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>c;
			if (c=='1' && cty[j].offeredSalary>=sv[i].minSalary)
				sv[i].Cty.pb(make_ele(j,cty[j].offeredSalary));
		}
	int x=0,z=m;
	long long y=0;
	for (int i=1;i<=n;i++)
	{
		set <ele>::iterator it;
		fors(sv[i].Cty)
		{
			int Index=it->id,luong=it->Salary;
			if (cty[Index].Offering<cty[Index].maxJobOffers)
			{
				cty[Index].Offering++;
				if (cty[Index].Offering==1) z--;
				y+=(long long)luong;
				x++;
				break;
			}
		}
	}
	cout<<x<<" "<<y<<" "<<z<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;
	while (T--) Process();
	return 0;
}
