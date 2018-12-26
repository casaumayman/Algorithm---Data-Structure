#include<bits/stdc++.h>
using namespace std;
const int MAXN=1048577;
typedef long long int64;
int64 n,L,R,a[MAXN];
map <int64,int64> ml,mr;
void Process()
{
	cin>>n>>L>>R;
	for (int64 i=1;i<=n;i++) cin>>a[i];
	int64 res=0;
	int64 il=0,ir=0;
	ml[0]=1;
	mr[0]=1;
	for (int64 i=1;i<=n;i++)
	{
		//if (il==n) break;
		if ((--ml[a[i-1]])==0) ml.erase(a[i-1]);
		if ((--mr[a[i-1]])==0) mr.erase(a[i-1]);
		while (ml.size()<L && il<n) ml[a[++il]]++;
		while (mr.size()<R && ir<n) mr[a[++ir]]++;
		while (ir<n && mr.find(a[ir+1])!=mr.end()) mr[a[++ir]]++;
		if (ml.size()==L) res+=(ir-il+1);
		//cout<<il<<" "<<ir<<"\n";
	}
	cout<<res;
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

