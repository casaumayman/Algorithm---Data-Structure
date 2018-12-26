#include<bits/stdc++.h>
using namespace std;
string s,t;
long long n=1;
void Process()
{
	cin>>s>>t;
	if (s.length()-t.length()<2)
	{
		cout<<0;
		return;
	}
	queue <char> que;
	for (int i=0;i<t.length();i++) que.push(t[i]);
	int i=0;
	char c;
	while (i<s.length())
	{
		if (que.empty())
		{
			n*=2;
			//cout<<s[i]<<" ";
		}
		else
		{
			c=que.front();
			if (s[i]==c) que.pop();
			else
			{
				//cout<<s[i]<<" "; 
				n*=2;
			}
		}
		i++;
	}
	cout<<(n-2)%10000000;
}
int main()
{
	Process();
	return 0;
}
