#include<bits/stdc++.h>
using namespace std;
map <int,int> kq;
int s1,s2,s3;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int maxs=INT_MIN;
	cin>>s1>>s2>>s3;
	for (int i=1;i<=s1;i++)
		for (int j=1;j<=s2;j++)
			for (int k=1;k<=s3;k++)
			{
				kq[i+j+k]++;
				if (kq[i+j+k]>maxs) maxs=kq[i+j+k];
			}
	map<int,int>::iterator it;
	for (it=kq.begin();it!=kq.end();it++)
		if (it->second==maxs)
		{
			cout<<it->first;
			return 0;
		}
}
