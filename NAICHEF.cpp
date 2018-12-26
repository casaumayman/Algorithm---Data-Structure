#include<bits/stdc++.h>
using namespace std;
int T,n,A,B;
void Process()
{
	int x,slA=0,slB=0;
	cin>>n>>A>>B;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		if (x==A) slA++;
		if (x==B) slB++;
	}
	printf("%.10lf\n",double(((slA*1.0)*slB)/(n*n)));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;
	while (T--) Process();
	return 0;
}

